---
contest_id: 2258
index: A
title: A. Odd Eraser
rating: 800
tags:
  - math
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2258/A
---

Given an array $a_1, a_2, \ldots, a_n$, you can apply the following operation any number of times (possibly zero):

- Choose an integer $k \geq 1$ such that $2k+1 \le m$ and $2k+1$ indices, $i_1, i_2, \ldots, i_{2k+1}$ ($1 \le i_1 \lt i_2 \lt \ldots \lt i_{2k+1} \le m$), where $m$ is the current length of the array. Then, remove the $i_{k+1}$-th element from the array.

Note that after any operation, the length of the array is reduced by one, and the rest of the array is concatenated.

Let $b_1, b_2, \ldots, b_m$ be the remaining array after all operations.

What is the maximum possible value of $\gcd(b_1, b_2, \ldots, b_m)$, where $\gcd$ of an array of integers denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of them?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains $n$ ($1 \le n \le 100$), denoting the size of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

### Output

For each test case, output a single integer — the maximum possible value.

### Example

#### Input

```
4
7
2 4 6 7 8 9 10
2
55 55555
4
1000000 1000 1 1000000000
5
23 32 23 32 23
```

#### Output

```
2
5
1000000
23
```

### Note

In the first test case, the given array is $[2, 4, 6, 7, 8, 9, 10]$.

Choosing indices $[1, 3, 4, 6, 7]$ results in the removal of $a_4 = 7$ and the array $[2, 4, 6, 8, 9, 10]$.

Then, choosing indices $[2, 5, 6]$ results in the removal of $a_5 = 9$ and the array $[2, 4, 6, 8, 10]$. You can't get an answer greater than $2$.
