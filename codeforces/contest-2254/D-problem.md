---
contest_id: 2254
index: D
title: D. Silhouette
rating: Unrated
tags:
  - constructive algorithms
  - math
  - sortings
time_limit: 2.5 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2254/D
---

Yousef has a secret array $a$ of $n$ strictly positive integers.

For each element $a_i$, its _shadow_ $b_i$ is the sum of all elements in $a$ that are strictly smaller than $a_i$. Formally:

You are given the shadow array $b$. Your task is to reconstruct the **lexicographically smallest** valid array $a$ consisting of strictly positive integers that satisfies the above condition. If no such array exists, output $-1$.

### Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains an integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the size of the array.

The second line of each test case contains $n$ integers $b_1, b_2, \dots, b_n$ ($0 \le b_i \le 2 \cdot 10^{14}$) — the shadow array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^{18}$) — the lexicographically smallest valid array $a$ that satisfies the condition. If no valid array exists, output $-1$ instead.

### Example

#### Input

```
8
1
0
5
0 4 0 4 14
3
4 0 0
3
0 0 0
3
0 1 1
4
1 1 1 1
7
0 4 4 4 4 4 9
5
0 0 0 3 3
```

#### Output

```
1
2 5 2 5 6
3 2 2
1 1 1
1 2 2
-1
-1
1 1 1 2 2
```

### Note

In the first test case, the answer is $a = [1]$. Since there is only one element, there are no strictly smaller elements, so its shadow is $0$. Thus $a=[1]$ is valid. It is also lexicographically smallest, because the only allowed values are positive integers, and $1$ is the smallest possible.

In the second test case, the answer is $a = [2,5,2,5,6]$:

- For each $2$, there is no smaller element in the array, so the shadow is $0$.
- For each $5$, the strictly smaller elements are the two $2$'s, so the shadow is $2+2=4$.
- For $6$, the strictly smaller elements are two $2$'s and two $5$'s, so the shadow is $2+2+5+5=14$.

Therefore the shadow array is exactly $b = [0,4,0,4,14]$.

In the third test case, the shadow array for $a = [3, 2, 2]$ is calculated as follows:

- For $a_1 = 3$, the strictly smaller elements in the array are the two $2$s. Their sum is $2 + 2 = 4$. So, $b_1 = 4$.
- For $a_2 = 2$, there are no strictly smaller elements in the array. So, $b_2 = 0$.
- For $a_3 = 2$, there are no strictly smaller elements in the array. So, $b_3 = 0$.

The resulting shadow array is $b = [4, 0, 0]$, which matches the input.
