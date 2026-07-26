import os
import re
import sys
import unicodedata
from pathlib import Path

import yaml
from bs4 import BeautifulSoup
from curl_cffi import requests
from markdownify import markdownify as md
from unicode_to_latex import UNICODE_TO_LATEX

CACHE_DIR = Path.home() / ".cache" / "codeforces"
CACHE_DIR.mkdir(parents=True, exist_ok=True)

# Web garbage cleaner
WEB_GARBAGE = re.compile(
  r"[\u0000-\u0008\u000B\u000C\u000E-\u001F]"
  r"|[\u007F]"
  r"|[\u00A0\u00AD]"
  r"|[\u200B-\u200F]"
  r"|[\u202A-\u202E]"
  r"|[\u2060-\u206F]"
  r"|[\uFEFF]"
)


def clean_markdown(text: str) -> str:
  text = unicodedata.normalize("NFKC", text)
  text = WEB_GARBAGE.sub("", text)
  # Markdownify sometimes escapes backslashes in math blocks
  text = text.replace("\\\\", "\\")
  return text.strip()


def fetch_cf_problem(contest_id: str, index: str, out_dir: str):
  index = index.upper()
  url = f"https://codeforces.com/problemset/problem/{contest_id}/{index}"
  cache_file = CACHE_DIR / f"{contest_id}_{index}.html"

  # Check cache
  if cache_file.exists():
    print(f"==> Using cached HTML from {cache_file}")
    html_text = cache_file.read_text(encoding="utf-8")
  else:
    # Using curl_cffi to bypass Cloudflare
    r = requests.get(url, timeout=20, impersonate="chrome")
    if r.status_code != 200:
      print(f"Error: HTTP {r.status_code} fetching {url}")
      sys.exit(1)
    html_text = r.text
    cache_file.write_text(html_text, encoding="utf-8")

  soup = BeautifulSoup(html_text, "html.parser")
  problem_div = soup.find("div", class_="problem-statement")

  if not problem_div:
    print(f"Error: Could not find problem statement for {contest_id}{index}")
    sys.exit(1)

  # Extract Meta (Title, Limits, Tags)
  title_el = problem_div.find("div", class_="title")
  title = title_el.text if title_el else f"Problem {index}"

  time_limit_el = problem_div.find("div", class_="time-limit")
  time_limit = str(time_limit_el.contents[-1]).strip() if time_limit_el else "Unknown"

  memory_limit_el = problem_div.find("div", class_="memory-limit")
  memory_limit = str(memory_limit_el.contents[-1]).strip() if memory_limit_el else "Unknown"

  tags = []
  for tag_box in soup.find_all("span", class_="tag-box"):
    tags.append(tag_box.text.strip())

  rating = "Unrated"
  clean_tags = []
  for t in tags:
    if t.startswith("*"):
      rating = t[1:]
    else:
      clean_tags.append(t)

  # CLEANUP HTML FOR MARKDOWN

  # Delete the entire header (Removes duplicate limits and IO specs)
  header_div = problem_div.find("div", class_="header")
  if header_div:
    header_div.decompose()

  # Convert CF section titles (Input, Output, Note) to Markdown H3
  for sec_title in problem_div.find_all("div", class_="section-title"):
    h3 = soup.new_tag("h3")
    h3.string = sec_title.get_text(strip=True)
    sec_title.replace_with(h3)

  # Convert sample test headers to Markdown H4
  for sample_title in problem_div.find_all("div", class_="title"):
    h4 = soup.new_tag("h4")
    h4.string = sample_title.get_text(strip=True)
    sample_title.replace_with(h4)

  # Convert older Codeforces math blocks (<span class="tex-span">) into LaTeX
  for tex in problem_div.find_all("span", class_="tex-span"):
    # Convert super/sub scripts to LaTeX ^ and _
    for sup in tex.find_all("sup"):
      sup.insert_before("^{")
      sup.insert_after("}")
      sup.unwrap()
    for sub in tex.find_all("sub"):
      sub.insert_before("_{")
      sub.insert_after("}")
      sub.unwrap()

    math_text = tex.get_text(strip=True)

    # Map unicode math symbols to LaTeX equivalents
    for uni_char, latex_cmd in UNICODE_TO_LATEX.items():
      math_text = math_text.replace(uni_char, f" {latex_cmd} ")

    # Clean up double spaces created by replacement padding
    math_text = re.sub(r"\s+", " ", math_text).strip()

    tex.replace_with(f"${math_text}$")

  # Normalize <pre> content: newer CF wraps each sample line in <div>
  for pre in problem_div.find_all("pre"):
    divs = pre.find_all("div", recursive=False)
    if divs:
      lines = [div.get_text(strip=True) for div in divs]
      pre.clear()
      pre.string = "\n".join(lines) + "\n"

  html_content = str(problem_div)

  # Convert modern Codeforces MathJax ($$$) into standard LaTeX ($)
  html_content = re.sub(r"\$\$\$(.*?)\$\$\$", r"$\1$", html_content, flags=re.DOTALL)

  # Convert HTML to MD
  # We turn off escaping for _ and * so it doesn't break math like $a_i$
  body_md = md(html_content, heading_style="ATX", escape_asterisks=False, escape_underscores=False).strip()

  body_md = clean_markdown(body_md)

  # Generate YAML Frontmatter
  frontmatter = {
    "contest_id": int(contest_id),
    "index": index,
    "title": title,
    "rating": int(rating) if rating.isdigit() else rating,
    "tags": clean_tags,
    "time_limit": time_limit,
    "memory_limit": memory_limit,
    "url": url,
  }

  yaml_header = "---\n" + yaml.dump(frontmatter, sort_keys=False, allow_unicode=True) + "---\n\n"

  md_path = os.path.join(out_dir, f"{index}-problem.md")
  with open(md_path, "w", encoding="utf-8") as f:
    f.write(yaml_header + body_md)

  print(f"==> Updated {md_path}")


if __name__ == "__main__":
  if len(sys.argv) < 4:
    print("Usage: python cf_fetch.py <contest_id> <index> <out_dir>")
    sys.exit(1)

  fetch_cf_problem(sys.argv[1], sys.argv[2], sys.argv[3])
