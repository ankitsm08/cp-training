---
contest_id: 2245
index: B
title: B. Delete and Concatenate
rating: 1100
tags:
  - greedy
time_limit: 1.5 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2245/B
---

You are given an array $a$ of $n$ integers. Your initial score is $0$.

You can perform the following two types of operations any number of times **until the array becomes empty**:

- Choose a single element. Add its value to your score, and remove it from the array.
- Choose two adjacent elements. Add the maximum of their values to your score, and remove both elements from the array. (This operation requires the array to have at least $2$ elements.)

After each operation, the remaining elements are concatenated without changing their relative order.

You are also given an integer $c$, which represents the cost of performing one operation. Every time you perform an operation (regardless of the type), $c$ is subtracted from your score.

Compute the maximum possible final score you can achieve.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $c$ ($1 \le n \le 2 \cdot 10^5$, $0 \le c \le 10^9$), representing the length of $a$ and the cost of performing one operation, respectively.

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($-10^9 \le a_i \le 10^9$), representing the elements of $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output an integer representing the maximum possible score you can achieve.

### Example

#### Input

```
5
1 0
-1
3 0
1 3 1
3 2
1 3 1
6 6
3 1 4 1 5 9
4 1000000000
-1000000000 -1000000000 -1000000000 -1000000000
```

#### Output

```
-1
5
0
0
-4000000000
```

### Note

In the first test case, your only possible choice is to perform the first operation once. Your score is $a_1-c=-1-0=-1$.

In the second test case, one optimal sequence of operations is:

- Choose $3$. Your score becomes $0+3-0=3$, and the array becomes $[1,1]$.
- Choose the first $1$. Your score becomes $3+1-0=4$, and the array becomes $[1]$.
- Choose $1$. Your score becomes $4+1-0=5$, and the array becomes empty.

In the third test case, one optimal sequence of operations is:

- Choose $3$ and the second $1$. Your score becomes $0+\max(3,1)-2=1$, and the array becomes $[1]$.
- Choose $1$. Your score becomes $1+1-2=0$, and the array becomes empty.
