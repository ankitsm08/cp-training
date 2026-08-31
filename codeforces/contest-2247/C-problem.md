---
contest_id: 2247
index: C
title: C. Inversion of a Subsequence
rating: 1100
tags:
  - greedy
  - math
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2247/C
---

You are given two arrays $a$ and $b$ of length $n$, consisting only of $0$ and $1$.

You may perform the following operation on $a$ any number of times:

1. Choose $k$ indices $1 \le i_1 \lt i_2 \lt \ldots \lt i_k \le n$, where $1 \le k \le n$ and $\sum\limits_{j = 1}^k a_{i_j}$ is **odd**. In other words, choose a non-empty subsequence [*1] of $a$ with an odd sum.
2. For each $1 \le j \le k$, set $a_{i_j} = 1 - a_{i_j}$. In other words, invert all elements of the chosen subsequence.

Find the minimum number of operations needed to transform $a$ into $b$, or determine that it is impossible.

[*1] A sequence $c$ is a subsequence of a sequence $d$ if $c$ can be obtained from $d$ by the deletion of several (possibly, zero or all) elements from arbitrary positions.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the arrays $a$ and $b$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($a_i \in \{0, 1\}$) — array $a$.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($b_i \in \{0, 1\}$) — array $b$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer — the minimum number of operations needed to transform $a$ into $b$, or $-1$ if it is impossible.

### Example

#### Input

```
5
1
0
0
2
1 0
0 1
3
1 1 1
0 0 0
4
1 0 1 0
0 1 0 1
5
1 0 1 0 1
1 1 1 1 1
```

#### Output

```
0
1
1
2
-1
```

### Note

In the first example, $a = b$, so no operations are needed. Therefore, the answer is $0$.

In the second example, we can perform an operation with the subsequence $[a_1, a_2]$. The sum of its elements is $1 + 0 = 1$, which is odd. This operation transforms $a$ as follows: $[\color{red}{1, 0}] \rightarrow [\color{red}{0, 1}]$. The resulting array equals $b$, so the answer is $1$.
