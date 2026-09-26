---
contest_id: 2260
index: A
title: A. Monocarp's Contest
rating: 800
tags:
  - implementation
time_limit: 2 seconds
memory_limit: 512 megabytes
url: https://codeforces.com/problemset/problem/2260/A
---

Monocarp is preparing a team programming contest. The contest has $n$ problems, each of which is either easy or hard. The problems are numbered from $1$ to $n$.

Monocarp wants the first and the last problems of the contest to be easy. In one operation, he can choose any two problems and swap them.

Determine the minimum number of operations required to make the first and the last problems easy, or report that it is impossible.

### Input

The first line contains an integer $t$ ($1 \le t \le 10^3$) — the number of test cases.

Each test case consists of two lines

- the first line contains one integer $n$ ($2 \le n \le 50$) — the number of problems in the contest;
- the second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 1$). If $a_i=0$, then the problem with number $i$ is easy; if $a_i=1$, then it is hard.

### Output

For each test case, print the minimum number of operations required to make the first and the last problems easy. If it is impossible to satisfy the requirement, print $-1$.

### Example

#### Input

```
4
2
0 0
2
0 1
6
1 0 0 1 0 0
5
1 0 0 1 1
```

#### Output

```
0
-1
1
2
```

### Note

In the first test case, the first and the last problems are already easy, so no operations are needed.

In the second test case, there is only one easy problem, so it is impossible to make both the first and the last problems easy.

In the third test case, one can swap the first and the second problems.

In the fourth test case, one can first swap the first and the second problems, and then — the third and the fifth problems.
