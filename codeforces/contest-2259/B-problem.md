---
contest_id: 2259
index: B
title: B. Minus Two
rating: 800
tags:
  - math
  - number theory
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2259/B
---

You are given an array $a_1, a_2, \ldots, a_n$. You may perform the following operation:

- **For all** indices $i$ ($1 \leq i \leq n$), set $a_i = |a_i - 2|$.

Find the maximum possible frequency of any integer in $a$ after performing the operation an arbitrary number (possibly zero) of times.

### Input

The first line of each input contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer denoting the maximum possible frequency of any integer in $a$ after performing the operation an arbitrary number of times.

### Example

#### Input

```
5
2
1 3
4
1 1 1 2
3
6 7 8
4
2 2 2 2
5
1 10 100 1000 100000
```

#### Output

```
2
3
1
4
3
```

### Note

In the first test case, we can perform the operation once to have $a = [|1 - 2|, |3 - 2|] = [1, 1]$, which means the maximum possible frequency of any integer in $a$ is $2$.

In the second test case, the maximum frequency of an integer in $a$ is $3$. It can be shown that, no matter how many operations we perform, the maximum possible frequency of an integer in $a$ will never exceed $3$.
