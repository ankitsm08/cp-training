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
    .venv/bin/python scripts/cf_fetch.py {{ contest_id }} $idx "$dir"

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

# refetch every problem still rated Unrated
cf-refetch-unrated:
    @files=$(rg -l "^rating: Unrated$" codeforces/*/*-problem.md 2>/dev/null || true); \
    if [ -z "$files" ]; then \
      echo "==> No unrated problems"; \
    else \
      for f in $files; do \
        contest=$(basename "$(dirname "$f")" | sed 's/^contest-//'); \
        idx=$(basename "$f" | cut -d- -f1); \
        just cf-refetch "$contest" "$idx"; \
      done; \
    fi

# force refetch a problem statement, bypassing the HTML cache
cf-refetch contest_id index:
    @echo "==> Force-refetching Codeforces problem (no cache)..."

    @padded_id=$(printf '%04d' {{ contest_id }}); \
    dir="codeforces/contest-$padded_id"; \
    mkdir -p "$dir"; \
    idx=$(echo "{{ index }}" | tr 'a-z' 'A-Z'); \
    .venv/bin/python scripts/cf_fetch.py --force {{ contest_id }} $idx "$dir"

    @just format-md "codeforces/contest-$(printf '%04d' {{ contest_id }})"
    @echo "==> Finished force-refetching and formatting"
