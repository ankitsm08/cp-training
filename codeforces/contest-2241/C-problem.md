---
contest_id: 2241
index: C
title: C. RemovevomeR
rating: 1000
tags:
  - greedy
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2241/C
---

You are given a binary string $s$ consisting only of the characters $\texttt{0}$ and $\texttt{1}$.

In one operation, you can do the following:

- Choose a substring [*1] of $s$ that is a palindrome [*2] of length at least $2$.
- Delete exactly one character from this chosen substring.

The remaining parts of the string are then concatenated to form the new string $s$.

Find the minimum possible length of the string $s$ that can be achieved after applying this operation any number of times (possibly zero).

[*1] A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

[*2] A string $a$ of length $m$ is said to be palindrome if $a_i = a_{m + 1 - i}$ for all $1 \le i \le m$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. Description of each test case follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$) — the length of the binary string $s$.

The second line of each test case contains a binary string $s$ of length $n$. It is guaranteed that each character of $s$ is either $\texttt{0}$ or $\texttt{1}$.

### Output

For each test case, print the minimum possible length of the string $s$ that can be achieved after applying the operation any number of times.

### Example

#### Input

```
4
4
0000
3
110
6
110011
6
101100
```

#### Output

```
1
2
1
1
```

### Note

In the first test case, the initial string is $\texttt{0000}$. We can perform the following sequence of operations:

- Choose the palindromic substring $\texttt{0000}$. Delete one $\texttt{0}$. The string becomes $\texttt{000}$.
- Choose the palindromic substring $\texttt{000}$. Delete one $\texttt{0}$. The string becomes $\texttt{00}$.
- Choose the palindromic substring $\texttt{00}$. Delete one $\texttt{0}$. The string becomes $\texttt{0}$.

The string $\texttt{0}$ contains no palindromic substrings of length at least $2$, so no further operations can be performed. The minimum possible length is $1$.

In the second test case, the initial string is $\texttt{110}$.

- Choose the palindromic substring $\texttt{11}$. Delete one $\texttt{1}$. The string becomes $\texttt{10}$.

The string $\texttt{10}$ contains no palindromic substrings of length at least $2$, so no further operations can be performed. The minimum possible length is $2$.
