---
contest_id: 2254
index: C2
title: C2. Marenol (hard version)
rating: 1200
tags:
  - greedy
  - sortings
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2254/C2
---

**This is the hard version of the problem. In this version, you are asked to determine the minimum number of operations to transform $a$ into $b$.**

Yousef has given you two binary strings, $a$ and $b$, of the same length $n$.

You are allowed to perform any of the following operations:

- Choose a substring [*1] in $a$ equal to $\texttt{001}$ and replace it with $\texttt{100}$, or vice versa (i.e. $\texttt{001} \rightarrow \texttt{100}$ or $\texttt{100} \rightarrow \texttt {001}$).
- Choose a substring in $a$ equal to $\texttt{110}$ and replace it with $\texttt{011}$, or vice versa (i.e. $\texttt{011} \rightarrow \texttt{110}$ or $\texttt{110} \rightarrow \texttt {011}$).

Your task is to determine the minimum number of operations required to transform string $a$ into string $b$. If it is impossible to transform $a$ into $b$ using the given operations, output $-1$ instead.

[*1] A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly zero or all) characters from the beginning and several (possibly zero or all) characters from the end.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of each string.

The second line of each test case contains a binary string $a$ ($|a| = n$), consisting of only characters $\texttt{0}$ and/or $\texttt{1}$.

The third line of each test case contains a binary string $b$ ($|b| = n$), consisting of only characters $\texttt{0}$ and/or $\texttt{1}$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output the minimum number of operations required to transform $a$ into $b$. If it is impossible, output $-1$ instead.

### Example

#### Input

```
5
4
0100
0001
4
0100
0010
6
110000
000011
8
10101010
10101010
5
01001
10010
```

#### Output

```
1
-1
4
0
3
```

### Note

In the first test case, we can choose the substring $a[2, 4] = \texttt{100}$ and replace it with $\texttt{001}$. This takes exactly $1$ operation.

In the second test case, it is impossible to transform $a$ into $b$, so the answer is $-1$.

In the third test case, we can do the following in order:

- $\texttt{1}$${\color{blue}{\texttt{100}}}$$\texttt{00}$ $\rightarrow$ $\texttt{1}$${\color{blue}{\texttt{001}}}$$\texttt{00}$
- $\texttt{100}$${\color{blue}{\texttt{100}}}$ $\rightarrow$ $\texttt{100}$${\color{blue}{\texttt{001}}}$
- ${\color{blue}{\texttt{100}}}$$\texttt{001}$ $\rightarrow$ ${\color{blue}{\texttt{001}}}$$\texttt{001}$
- $\texttt{00}$${\color{blue}{\texttt{100}}}$$\texttt{1}$ $\rightarrow$ $\texttt{00}$${\color{blue}{\texttt{001}}}$$\texttt{1}$

This takes $4$ operations. It can be shown that $4$ is the minimum answer.
