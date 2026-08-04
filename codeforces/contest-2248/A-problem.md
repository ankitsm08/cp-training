---
contest_id: 2248
index: A
title: A. You Delete, I Delete
rating: 800
tags:
  - greedy
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2248/A
---

Alice and Bob are given a binary string [*1] $s$ of length $n$. It contains at least one $\mathtt{0}$ and at least one $\mathtt{1}$.

They each perform exactly **one** operation in the following order:

- First, Alice chooses an occurrence of $\mathtt{0}$ in $s$ and deletes it.
- Then, Bob chooses an occurrence of $\mathtt{1}$ in the resulting string and deletes it.

Alice wants the final string to be lexicographically [*2] as large as possible, while Bob wants it to be lexicographically as small as possible. Determine the final string if both players act optimally.

[*1] A binary string is a string consisting only of the characters $\mathtt{0}$ and $\mathtt{1}$.

[*2] For two distinct binary strings $a$ and $b$ of the same length, $a$ is lexicographically smaller than $b$ if, at the first position where they differ, $a$ has the smaller digit.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The only line of each test case contains a binary string $s$ of length $n$ ($3 \le n \le 100$).

It is guaranteed that $s$ contains at least one $\mathtt{0}$ and at least one $\mathtt{1}$.

### Output

For each test case, output the final string if both players act optimally.

### Example

#### Input

```
4
101
11001
0010
0101010000010100100101
```

#### Output

```
1
101
00
01010000010100100101
```

### Note

In the first test case, Alice must delete the only $\mathtt{0}$. Bob may delete either occurrence of $\mathtt{1}$, so the resulting string is $\mathtt{1}$.

In the second test case, Alice may delete either occurrence of $\mathtt{0}$. Bob optimally deletes one of the first two occurrences of $\mathtt{1}$, so the resulting string is $\mathtt{101}$.

In the third test case, Alice may delete any occurrence of $\mathtt{0}$. Bob then deletes the only occurrence of $\mathtt{1}$, so the resulting string is $\mathtt{00}$.
