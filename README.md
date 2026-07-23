# Competitive Programming Training

My personal collection of competitive programming solutions, notes, and template code for data structures and algorithms. Primarily focused on **Codeforces** (the main training ground) with occasional **AtCoder** on the side. Written in **C++**, the standard pragma setup, `<bits/stdc++.h>`, fast I/O, the usual competitive programming workflow.

## Repository Structure

- Each contest lives in its own folder
- A problem file contains the full statement with YAML frontmatter (contest ID, rating, tags, limits)
- Solutions use the standard template with `solve()` and fast I/O

```text
codeforces/
  ├── contest-4/
  │   ├── problem-A.md
  │   ├── solution-A.cpp
  │   └── ...
  ├── contest-{id}/
  │   ├── problem-{idx}.md
  │   └── solution-{idx}cpp
templates/
  ├── base.cpp
  ├── **/
  │   └── *.cpp
scripts/
  ├── cf_fetch.py
  └── unicode_to_latex.py
```

## Tooling & Automation

A `justfile` with `fd` and `clang-format` keeps everything consistent.

### Commands

Sets up a Python virtual environment and installs required dependencies for the fetch scripts:

```bash
just venv
```

Creates a new Codeforces problem directory, copies the base template, fetches the problem statement, and formats everything (e.g., `just cf 4 a`):

```bash
just cf <contest_id> <index>
```

Runs the appropriate formatters on all supported files:

```bash
just format-all
```

Formatters used are:

- `prettier` (Markdown)
- `clang-format` (C/C++)

## License & Disclaimer

### Problem Statements

All problem descriptions, test cases, and platform-specific resources are the property of their respective platforms (Codeforces, AtCoder). Used here strictly for educational purposes.

### Solutions, Notes, & Scripts

All original C++ source code, templates, algorithms, and Python scripts in this repository are licensed under the **MIT License**.  
See the [LICENSE](LICENSE) file for details.
