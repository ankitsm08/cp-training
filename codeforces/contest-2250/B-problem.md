---
contest_id: 2250
index: B
title: B. String Construction
rating: Unrated
tags:
  - constructive algorithms
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2250/B
---

You are given two integers $n$ and $k$.

Construct a binary string$^{\text{∗}}$ $s$ of length $n$, such that both of the following conditions hold:

- The absolute difference between the number of characters $\mathtt{0}$ and the number of characters $\mathtt{1}$ in $s$ is at most $1$.
- There are exactly $k$ pairs of adjacent equal characters in $s$. Formally, there are exactly $k$ indices $i$ ($1 \le i \le n-1$) satisfying $s_i = s_{i + 1}$.

Or determine that no such string exists.

$^{\text{∗}}$A binary string is a string where each character is either $\mathtt{0}$ or $\mathtt{1}$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

The only line of each test case contains two integers $n$ and $k$ ($2 \le n \le 2 \cdot 10^5$, $0 \le k \le n-1$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a binary string $s$ of length $n$ — the string you constructed. Print $-1$ if such a string does not exist.

If there are multiple answers, you may output any of them.

### Example

#### Input

```
8
5 2
4 3
6 1
5 0
7 3
4 2
3 2
7 4
```

#### Output

```
01110
-1
101001
01010
0100011
0011
-1
0111000
```

### Note

In the first test case, one possible answer is $s=\mathtt{01110}$. It contains three characters $\mathtt{1}$ and two characters $\mathtt{0}$, and there are exactly $2$ adjacent equal pairs in $s$: $(s_2, s_3)$ and $(s_3, s_4)$.

In the second test case, $k=n-1$. All characters in $s$ should be equal, so the numbers of characters $\mathtt{0}$ and $\mathtt{1}$ could not differ by at most $1$. Thus, the answer is $-1$.

In the third test case, note that $\mathtt{010110}$ is also a possible answer.
