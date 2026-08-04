---
contest_id: 2250
index: C
title: C. Rank Subsequence
rating: 1300
tags:
  - brute force
  - greedy
  - implementation
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2250/C
---

You are given $n$ elements arranged in a line, numbered $1, 2, \ldots, n$ from left to right.

You may delete any number of elements (possibly none). The remaining elements form a **subsequence** and keep their relative order. Let the length of this subsequence be $m$. If the element with original index $i$ becomes the $j$-th element of the subsequence ($1 \le j \le m$), define

- its _left rank_ as $j$, and
- its _right rank_ as $m - j + 1$.

For each element, you are given two integer segments $[l_i, r_i]$ and $[u_i, v_i]$. The $i$-th element is _valid_ in a subsequence of length $m$ if and only if, when it occupies position $j$ in that subsequence, both of the following hold:

- Its _left rank_ is not in the range $[l_i, r_i]$ (i.e., $j \notin [l_i, r_i]$);
- Its _right rank_ is not in the range $[u_i, v_i]$ (i.e., $m - j + 1 \notin [u_i, v_i]$).

A subsequence is _valid_ if every element remaining in it is _valid_.

Find the maximum possible length of a _valid_ subsequence. The answer may be $0$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 5000$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1\le n\le 5000$) — the number of elements.

Then $n$ lines follow, the $i$-th line containing the four integers $l_i$, $r_i$, $u_i$, and $v_i$ ($1\le i\le n$, $1\le l_i\le r_i\le n$, $1\le u_i\le v_i\le n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $5000$.

### Output

For each test case, print one integer — the maximum possible length of a _valid_ subsequence.

### Example

#### Input

```
5
1
1 1 1 1
4
2 2 2 2
1 1 1 1
1 1 1 1
1 1 2 2
5
1 1 3 3
2 2 2 2
3 3 1 1
1 5 1 5
5 5 5 5
2
2 2 1 1
1 1 2 2
6
1 1 6 6
1 2 5 6
2 3 4 5
3 4 3 4
4 5 2 3
5 6 1 2
```

#### Output

```
0
4
3
2
3
```

### Note

In the first test case, the only element cannot form a _valid_ subsequence of length $1$, so the answer is $0$.

In the second test case, all $4$ elements can be kept. Their pairs of _left_ and _right ranks_ are $(1, 4)$, $(2, 3)$, $(3, 2)$, and $(4, 1)$, respectively, and all of them are _valid_.

In the third test case, one optimal choice is to keep the elements with original indices $2$, $3$, and $5$.

In the fourth test case, keeping both elements yields a _valid_ subsequence of length $2$. Note that no _valid_ subsequence of length $1$ exists.

In the fifth test case, one optimal choice is to keep the elements with original indices $3$, $4$, and $5$.
