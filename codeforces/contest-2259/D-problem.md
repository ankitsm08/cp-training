---
contest_id: 2259
index: D
title: D. MEX Multiset
rating: 1200
tags:
  - constructive algorithms
  - greedy
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2259/D
---

You are given an array $a_1, a_2, \ldots, a_n$. There exist $3$ initially empty multisets $A, B, C$, and for each index $i$ ($1 \leq i \leq n$), you may put $a_i$ into **exactly one** of $A$, $B$, or $C$.

Determine whether it is possible to put the elements into the multisets such that $\operatorname{MEX}(A) + \operatorname{MEX}(B) + \operatorname{MEX}(C) \geq 2 \cdot \max(\operatorname{MEX}(A), \operatorname{MEX}(B), \operatorname{MEX}(C))$ [*1] . If so, output a construction that achieves this.

[*1] $\operatorname{MEX}(D)$ is defined as the smallest non-negative integer that is not present in the set $D$. For example, $\operatorname{MEX}([1, 2, 0, 5]) = 3$, and $\operatorname{MEX}([1, 2, 4, 9]) = 0$. The $\operatorname{MEX}$ of an empty set is $0$.

### Input

The first line of each input contains $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains $n$ ($3 \leq n \leq 2 \cdot 10^5$) — the length of $a$.

The second line of each test case contains $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 10^9$) — the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

If a valid distribution of elements into the multisets exists, output $\texttt{YES}$. Otherwise, output $\texttt{NO}$.

If the answer is $\texttt{YES}$, output a string $s$ of length $n$ on a new line, such that $s_i = \texttt{A}$ if the $i$-th element was put into the multiset $A$, $s_i = \texttt{B}$ if the $i$-th element was put into the multiset $B$, and $s_i = \texttt{C}$ if the $i$-th element was put into the multiset $C$.

You can output the answer in any case (upper or lower). For example, the strings $\texttt{YES}$, $\texttt{yes}$, $\texttt{yEs}$, and $\texttt{Yes}$ will be recognized as positive responses, and the strings $\texttt{NO}$, $\texttt{no}$, $\texttt{No}$ will be recognized as negative responses. Additionally, the strings $\texttt{AABCAAA}$, $\texttt{aabcaaa}$, and $\texttt{aaBcaaa}$ will be recognized as the same answer.

If there are multiple possible outputs, output any.

### Example

#### Input

```
5
6
1 0 0 1 2 1
4
0 0 0 0
3
0 2 2
4
6 7 6 7
5
0 0 0 1 2
```

#### Output

```
YES
ABABCA
YES
ABAC
NO
YES
AAAB
YES
ABCAB
```

### Note

In the first test case, we can have $A = \{0, 1, 1\}$, $B = \{0, 1\}$, $C = \{2\}$, meaning $\operatorname{MEX}(A) + \operatorname{MEX}(B) + \operatorname{MEX}(C) = 4$, and $2 \cdot \max(\operatorname{MEX}(A), \operatorname{MEX}(B), \operatorname{MEX}(C)) = 2 \cdot \max(2, 2, 0) = 4$.

In the third test case, it can be shown that there are no valid distributions.
