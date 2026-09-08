---
contest_id: 2259
index: C
title: C. 101
rating: 1000
tags:
  - constructive algorithms
  - greedy
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2259/C
---

The score of an array $b$ of length $m$ is defined as the maximum length of a subarray of $b$ such that the first and last elements of the subarray are equal to $1$ and all other elements in the subarray are equal to $0$. Formally, the score of $b$ is equal to the maximum integer $k$ for which there exists an index $i$ such that:

- $1 \leq i \leq m - k + 1$
- $b_i = b_{i+k-1} = 1$
- $b_{i+1} = b_{i+2} = \ldots = b_{i+k-2} = 0$

If there is no subarray meeting the requirements, the score of $b$ is $0$.

You are given an array $a_1, a_2, \ldots, a_n$, such that each element is equal to one of $-1$, $0$, or $1$. Replace each $-1$ with either a $0$ or $1$ such that the score of $a$ is maximal over all possible ways to replace the $-1$s in $a$.

### Input

The first line of each input contains $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of $a$.

The second line of each test case contains $a_1, a_2, \ldots, a_n$ ($a_i \in \{-1, 0, 1\}$) — the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output $n$ space separated integers representing $a$ after the $-1$s were replaced with $0$s or $1$s. If there are multiple possible solutions, output any.

### Example

#### Input

```
10
6
1 0 -1 0 0 1
7
0 -1 0 0 1 0 1
5
-1 0 0 -1 0
4
0 0 0 0
1
-1
6
1 0 1 0 0 -1
7
0 1 0 0 0 1 0
6
-1 -1 -1 -1 -1 -1
7
-1 0 1 -1 0 0 1
3
-1 0 0
```

#### Output

```
1 0 0 0 0 1
0 1 0 0 1 0 1
1 0 0 1 0
0 0 0 0
1
1 0 1 0 0 1
0 1 0 0 0 1 0
1 0 0 0 0 1
0 0 1 0 0 0 1
1 0 0
```

### Note

In the first test case, we can change the only $-1$ to a $0$, making $a = [1, 0, 0, 0, 0, 1]$. Since the first and last elements of $a$ are equal to $1$, and all other elements are $0$, the score of $a$ is $6$.

In the third test case, changing both $-1$s to $1$s makes $a = [1, 0, 0, 1, 0]$, and the largest subarray that satisfies the conditions in the statement is from the $1$-st index to the $4$-th index.

In the fifth test case, we set the only $-1$ to $1$, making $a = [1]$, meaning the largest subarray that satisfies the conditions in the statement is the full array.
