---
contest_id: 2256
index: B
title: B. Domino Tiles
rating: 1000
tags:
  - implementation
  - math
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2256/B
---

Nygglatho returns from the market with an old box of tiles whose painted marks have begun to fade. Before she can put it away, Chtholly and the young fairies have already spread the tiles across the dining table and turned them into a puzzle.

There is a row of $n$ tiles. Each tile should be marked with either $\mathtt 0$ or $\mathtt 1$. However, some of the marks have faded away.

The current row is represented by a string $s$ of length $n$. Each character of $s$ is $\mathtt{0}$, $\mathtt{1}$, or $\mathtt{?}$. Chtholly must replace every $\mathtt{?}$ with either $\mathtt{0}$ or $\mathtt{1}$.

After replacement, for every $1 \le i \lt n$, the two neighboring tiles $s_i$ and $s_{i+1}$ form a domino of weight $(s_i + s_{i+1})$. Note that two consecutive dominoes share exactly one tile. The completed row is valid if every two consecutive dominoes have different weights.

Determine the number of different [*1] ways to replace all $\mathtt{?}$ characters so that the completed row is valid. Output the answer modulo $998\,244\,353$.

[*1] Two ways of replacement are considered different if the resulting strings are different.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of tiles.

The second line contains the string $s$ of length $n$, where $s_i= \mathtt{0}$, $\mathtt{1}$, or $\mathtt{?}$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output one integer — the number of valid ways to replace all $\mathtt{?}$ characters, modulo $998\,244\,353$.

### Example

#### Input

```
4
2
??
5
0?1??
5
0?0??
8
00110011
```

#### Output

```
4
2
0
1
```

### Note

In the first test case, there is only one domino, so every completion is valid. The valid completed strings are $\mathtt{00}$, $\mathtt{01}$, $\mathtt{10}$, and $\mathtt{11}$.

In the second test case, the valid completed strings are $\mathtt{00110}$ and $\mathtt{01100}$.

In the third test case, there are no valid completed strings.

In the fourth test case, the only valid completed string is $\mathtt{00110011}$.
