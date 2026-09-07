---
contest_id: 2258
index: B1
title: B1. Carrot Chopdown (Easy Version)
rating: 900
tags:
  - brute force
  - games
  - math
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2258/B1
---

**This is the easy version of the problem. The difference between the versions is that in this version, you only need to solve the problem for k=1k=1$k=1$. You can hack only if you solved all versions of this problem.**

_Alp loves carrots. Since he hasn't eaten lunch yet, he wants to buy a carrot salad to eat outside. However, he has a weird obsession: all the carrots must be the exact same length; otherwise, the salad doesn't look aesthetically pleasing to him. Since he is in the middle of the street and doesn't have a knife, he can't cut the carrots himself. You need to divide all the carrots using your machine and sell them to Alp._

You are given nn$n$ delicious carrots with sizes a1,a2,...,ana1,a2,...,an$a_1, a_2, \ldots, a_n$. You are also given a cutting machine, which works as follows.

- For each operation, you choose a set of carrots (you can choose chopped carrots again) and a positive integer xx$x$ **(not necessarily the same for each operation)**.
- After that, consider every chosen carrot, let its length be ll$l$. If l≤xl≤x$l \le x$, this carrot is unaffected; otherwise, it is divided into two carrots of sizes xx$x$ and l−xl−x$l-x$.

We'll sell some of the final carrots to an interesting guy who wants them all to be the same length.

We are asking you to determine the maximum number of carrots we can sell after using this machine exactly kk$k$ times. Solve the problem for only k=1k=1$k=1$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases tt$t$ (1≤t≤1041≤t≤104$1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains nn$n$ and mm$m$ (1≤n,m≤2⋅1051≤n,m≤2⋅105$1 \le n,m \le 2 \cdot 10^5$), denoting the number of carrots and the maximum possible length of a carrot.

The second line of each test case contains nn$n$ integers a1,a2,...,ana1,a2,...,an$a_1, a_2, \ldots, a_n$ (1≤ai≤m1≤ai≤m$1 \le a_i \le m$), denoting the initial carrot sizes.

It is guaranteed that the sum of nn$n$ over all test cases does not exceed 2⋅1052⋅105$2 \cdot 10^5$ and the sum of mm$m$ over all test cases does not exceed 2⋅1052⋅105$2 \cdot 10^5$.

### Output

For each test case, output a single integer — the answer for k=1k=1$k=1$.

### Example

#### Input

```
6
5 4
1 2 3 4 4
5 8
1 1 8 8 8
1 8
6
7 9
1 7 5 1 7 5 3
4 1
1 1 1 1
3 5
3 1 5
```

#### Output

```
6
6
2
7
4
3
```

### Note

In the first test case, the given carrots are [1,2,3,4,4][1,2,3,4,4]$[1, 2, 3, 4, 4]$.

For k=1k=1$k=1$, it is best to choose x=2x=2$x=2$ with the set [2,3,4,4][2,3,4,4]$[2, 3, 4, 4]$. After the operation, we'll get [1,2,2,1,2,2,2,2][1,2,2,1,2,2,2,2]$[1, 2, 2, 1, 2, 2, 2, 2]$. We can sell 66$6$ carrots of length 22$2$.
