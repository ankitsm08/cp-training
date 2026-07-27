import os
import re
import sys
import unicodedata
from pathlib import Path

import yaml
from bs4 import BeautifulSoup
from camoufox.sync_api import Camoufox
from markdownify import markdownify as md
from unicode_to_latex import UNICODE_TO_LATEX

CACHE_DIR = Path.home() / ".cache" / "codeforces"
CACHE_DIR.mkdir(parents=True, exist_ok=True)

# Non-printable control characters and web artifacts cleaner
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
  text = text.replace("\\\\", "\\")
  return text.strip()


def get_problem_html(contest_id: str, index: str) -> str:
  """Fetch problem statement HTML headlessly using Camoufox."""
  url = f"https://codeforces.com/problemset/problem/{contest_id}/{index}"

  try:
    with Camoufox(headless=True) as browser:
      page = browser.new_page()
      page.goto(url)
      page.wait_for_selector("div.problem-statement", timeout=25000)
      return page.content()
  except Exception as e:
    print(f"Error fetching problem HTML for {contest_id}{index}: {e}", file=sys.stderr)
    sys.exit(1)


def fetch_cf_problem(contest_id: str, index: str, out_dir: str):
  index = index.upper()
  url = f"https://codeforces.com/problemset/problem/{contest_id}/{index}"
  cache_file = CACHE_DIR / f"{contest_id}_{index}.html"

  if cache_file.exists():
    html_text = cache_file.read_text(encoding="utf-8")
  else:
    html_text = get_problem_html(contest_id, index)
    cache_file.write_text(html_text, encoding="utf-8")

  soup = BeautifulSoup(html_text, "html.parser")
  problem_div = soup.find("div", class_="problem-statement")

  if not problem_div:
    print(f"Error: Could not find problem statement for {contest_id}{index}", file=sys.stderr)
    sys.exit(1)

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

  # 1. Remove statement header containing redundant metadata
  header_div = problem_div.find("div", class_="header")
  if header_div:
    header_div.decompose()

  # 2. Remove "Copy" buttons from sample test blocks
  for copier in problem_div.find_all("div", class_="input-output-copier"):
    copier.decompose()

  # 3. Map Codeforces font style classes to standard HTML tags
  for span in problem_div.find_all("span", class_=True):
    classes = span.get("class")
    if isinstance(classes, list):
      if "tex-font-style-tt" in classes:
        span.name = "code"
      elif "tex-font-style-bf" in classes:
        span.name = "b"
      elif "tex-font-style-it" in classes:
        span.name = "i"

  # 4. Format section headings
  for sec_title in problem_div.find_all("div", class_="section-title"):
    h3 = soup.new_tag("h3")
    h3.string = sec_title.get_text(strip=True)
    sec_title.replace_with(h3)

  for sample_title in problem_div.find_all("div", class_="title"):
    h4 = soup.new_tag("h4")
    h4.string = sample_title.get_text(strip=True)
    sample_title.replace_with(h4)

  # 5. Convert legacy Codeforces HTML math elements to LaTeX
  for tex in problem_div.find_all("span", class_="tex-span"):
    for sup in tex.find_all("sup"):
      sup.insert_before("^{")
      sup.insert_after("}")
      sup.unwrap()
    for sub in tex.find_all("sub"):
      sub.insert_before("_{")
      sub.insert_after("}")
      sub.unwrap()

    math_text = tex.get_text(strip=True)

    for uni_char, latex_cmd in UNICODE_TO_LATEX.items():
      math_text = math_text.replace(uni_char, f" {latex_cmd} ")

    math_text = re.sub(r"\s+", " ", math_text).strip()
    tex.replace_with(f"${math_text}$")

  # 6. Normalize sample test block structure
  for pre in problem_div.find_all("pre"):
    divs = pre.find_all("div", recursive=False)
    if divs:
      lines = [div.get_text(strip=True) for div in divs]
      pre.clear()
      pre.string = "\n".join(lines) + "\n"

  html_content = str(problem_div)
  html_content = re.sub(r"\$\$\$(.*?)\$\$\$", r"$\1$", html_content, flags=re.DOTALL)

  body_md = md(
    html_content,
    heading_style="ATX",
    escape_asterisks=False,
    escape_underscores=False,
  ).strip()

  body_md = clean_markdown(body_md)

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


if __name__ == "__main__":
  if len(sys.argv) < 4:
    print("Usage: python cf_fetch.py <contest_id> <index> <out_dir>", file=sys.stderr)
    sys.exit(1)

  fetch_cf_problem(sys.argv[1], sys.argv[2], sys.argv[3])
