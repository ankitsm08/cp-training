---
contest_id: 2254
index: B
title: B. Evanescent
rating: Unrated
tags:
  - implementation
  - strings
  - two pointers
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2254/B
---

Let $f(s)$ be the compressed version of a string $s$, formed by replacing every maximal contiguous block of identical characters with a single copy of that character. For example, $f($"`aabbcc`"$) \ = \$"`abc`".

Let $|s|$ denote the length of a string $s$. Following this, $|f(s)|$ denotes the length of the compressed string. For example:

- $|f($"`aabbcc`"$)| =$ $|$"`abc`"$|$ $= 3$
- If the string is empty, its length is $0$.

Yousef has given you a string $s$ consisting of $n$ lowercase Latin letters. You must delete **exactly** one character $s_i$ ($2 \le i \le n - 1$) to form a new string $s'$, and then find the minimum possible value of $|f(s')|$.

Note that you **cannot** delete $s_1$ or $s_n$.

### Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains an integer $n$ ($3 \le n \le 2 \cdot 10^5$) — the length of the string.

The second line of each test case contains a string $s$ ($|s| = n$), consisting of lowercase Latin letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer — the minimum possible length of the resulting compressed string after deleting one character.

### Example

#### Input

```
9
3
abb
3
aab
3
abc
4
abaa
4
abba
5
eeeee
6
yyssee
7
abacaba
18
goodluckandhavefun
```

#### Output

```
2
2
2
1
3
1
3
5
16
```

### Note

In the first test case, we can only delete the character $s_2 =$ '`b`', producing a string $s' =$ "`ab`", with $|f(s')| = 2$. Therefore, $2$ is the minimum length achievable.

In the fourth test case, we can delete the character $s_2 =$ '`b`'. The resulting string is $s' =$ "`aaa`" with $f(s') =$ "`a`", so $|f(s')| = 1$.

In the sixth test case, deleting any valid character results in $f(s') =$ "`e`" and $|f(s')| = 1$.

In the eighth test case, we can delete the character $s_4 =$ '`c`'. The resulting string is $s' =$ "`abaaba`" with $f(s') =$ "`ababa`" and $|f(s')| = 5$.
