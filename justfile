set shell := ["bash", "-eu", "-o", "pipefail", "-c"]

# list available recipes
default:
    @just --list

# setup python venv
venv:
    @echo "==> Creating venv..."
    ls .venv || uv venv --python=3.14
    uv pip install requests markdownify pandas numpy beautifulsoup4 pyyaml curl_cffi camoufox
    .venv/bin/python -m camoufox fetch

format-md target="":
    @echo "==> Formatting Markdown files..."
    @if [ -z "{{ target }}" ]; then \
      fd -tf -e md -X prettier --write --color; \
    elif [[ "{{ target }}" =~ ^[0-9]+$ ]]; then \
      padded=$(printf '%04d' {{ target }}); \
      fd -tf -e md . "codeforces/contest-$padded" -X prettier --write --color; \
    else \
      fd -tf -e md . "{{ target }}" -X prettier --write --color; \
    fi

format-cpp target="":
    @echo "==> Formatting C/C++ files..."
    @if [ -z "{{ target }}" ]; then \
      fd -tf -e c -e cpp -e h -e hpp -e hh -X clang-format -i; \
    elif [[ "{{ target }}" =~ ^[0-9]+$ ]]; then \
      padded=$(printf '%04d' {{ target }}); \
      fd -tf -e c -e cpp -e h -e hpp -e hh . "codeforces/contest-$padded" -X clang-format -i; \
    else \
      fd -tf -e c -e cpp -e h -e hpp -e hh . "{{ target }}" -X clang-format -i; \
    fi

# format all files
format-all:
    @echo "==> Formatting all files..."
    @just format-md
    @just format-cpp

# create ONE new Codeforces problem + fetch
cf contest_id index:
    @echo "==> Creating Codeforces problem..."

    @padded_id=$(printf '%04d' {{ contest_id }}); \
    dir="codeforces/contest-$padded_id"; \
    mkdir -p "$dir"; \
    idx=$(echo "{{ index }}" | tr 'a-z' 'A-Z'); \
    cpp_file="$dir/$idx-solution.cpp"; \
    if [ ! -f "$cpp_file" ]; then \
      cp "templates/base.cpp" "$cpp_file"; \
      echo "==> Populated $cpp_file"; \
    else \
      echo "==> $cpp_file already exists"; \
    fi; \
    .venv/bin/python scripts/cf_fetch.py "$dir" {{ contest_id }} $idx

    @just format-md "codeforces/contest-$(printf '%04d' {{ contest_id }})"
    @just format-cpp "codeforces/contest-$(printf '%04d' {{ contest_id }})"
    @echo "==> Finished fetching and formatting"

# list problems still rated Unrated (contest problems needing a rating refresh)
cf-unrated:
    @echo "==> Problems with rating: Unrated..."
    @files=$(rg -l "^rating: Unrated$" codeforces/*/*-problem.md 2>/dev/null || true); \
    if [ -z "$files" ]; then \
      echo "(none)"; \
    else \
      echo "$files"; \
    fi

# refetch every problem still rated Unrated, batched per contest (one browser session per contest)
cf-refetch-unrated:
    @files=$(rg -l "^rating: Unrated$" codeforces/*/*-problem.md 2>/dev/null || true); \
    if [ -z "$files" ]; then \
      echo "==> No unrated problems"; \
    else \
      for dir in $(for f in $files; do dirname "$f"; done | sort -u); do \
        ids=""; \
        for f in $files; do \
          [ "$(dirname "$f")" = "$dir" ] && ids="$ids $(basename "$f" | cut -d- -f1)"; \
        done; \
        contest=$(basename "$dir" | sed 's/^contest-//'); \
        echo "==> Refreshing $contest: $ids"; \
        .venv/bin/python scripts/cf_fetch.py --force "$dir" "$contest" $ids; \
      done; \
    fi

# force refetch a problem statement, bypassing the HTML cache
cf-refetch contest_id index:
    @echo "==> Force-refetching Codeforces problem (no cache)..."

    @padded_id=$(printf '%04d' {{ contest_id }}); \
    dir="codeforces/contest-$padded_id"; \
    mkdir -p "$dir"; \
    idx=$(echo "{{ index }}" | tr 'a-z' 'A-Z'); \
    .venv/bin/python scripts/cf_fetch.py --force "$dir" {{ contest_id }} $idx

    @just format-md "codeforces/contest-$(printf '%04d' {{ contest_id }})"
    @echo "==> Finished force-refetching and formatting"

# bulk fetch several problems of one contest in a single browser session
# (e.g. `just cf-bulk 2254 a b c1 c2`); seeds missing solutions
cf-bulk contest_id +indices:
    @echo "==> Bulk creating Codeforces problems (single browser session)..."

    @padded_id=$(printf '%04d' {{ contest_id }}); \
    dir="codeforces/contest-$padded_id"; \
    mkdir -p "$dir"; \
    ids=""; \
    for idx in {{ indices }}; do \
      up=$(echo "$idx" | tr 'a-z' 'A-Z'); \
      ids="$ids $up"; \
      cpp_file="$dir/$up-solution.cpp"; \
      if [ ! -f "$cpp_file" ]; then \
        cp "templates/base.cpp" "$cpp_file"; \
        echo "==> Populated $cpp_file"; \
      fi; \
    done; \
    .venv/bin/python scripts/cf_fetch.py "$dir" {{ contest_id }} $ids

    @just format-md "codeforces/contest-$(printf '%04d' {{ contest_id }})"
    @just format-cpp "codeforces/contest-$(printf '%04d' {{ contest_id }})"
    @echo "==> Finished bulk fetch and formatting"

# force refetch every problem statement of a contest in a single browser session;
# seeds missing solutions (use after the contest ends and ratings land)
cf-refresh contest_id:
    @echo "==> Refreshing whole contest (single browser session, no cache)..."

    @padded_id=$(printf '%04d' {{ contest_id }}); \
    dir="codeforces/contest-$padded_id"; \
    if [ ! -d "$dir" ]; then \
      echo "No contest directory: $dir"; \
      exit 1; \
    fi; \
    ids=$(shopt -s nullglob; for f in "$dir"/*-problem.md; do basename "$f"; done | sed 's/-problem\.md$//' | sort | tr '\n' ' '); \
    if [ -z "$ids" ]; then \
      echo "No problem statements found in $dir"; \
      exit 1; \
    fi; \
    echo "==> Problems: $ids"; \
    for idx in $ids; do \
      cpp_file="$dir/$idx-solution.cpp"; \
      if [ ! -f "$cpp_file" ]; then \
        cp "templates/base.cpp" "$cpp_file"; \
        echo "==> Populated $cpp_file"; \
      fi; \
    done; \
    .venv/bin/python scripts/cf_fetch.py --force "$dir" {{ contest_id }} $ids

    @just format-md "codeforces/contest-$(printf '%04d' {{ contest_id }})"
    @echo "==> Finished refreshing contest"
