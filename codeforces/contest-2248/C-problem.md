---
contest_id: 2248
index: C
title: C. Maximize the Score
rating: 1300
tags:
  - dp
  - greedy
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2248/C
---

You are given an array a of length 2n. Each integer from 1 to n occurs exactly twice in a.

Initially, your score is 0.

You can repeatedly perform the following operation while a is non-empty:

- Choose an integer x that is present in a.
- Let l and r be the indices of the leftmost and rightmost occurrences of x in the current array, respectively. If x occurs only once, then l=r.
- Add (r−l+1)2 to your score.
- Delete the elements al,al+1,...,ar from a. The remaining elements are concatenated without changing their order and re-indexed starting from 1.

Find the maximum possible score after making the array empty.

### Input

Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤2⋅105).

The second line contains 2n integers a1,a2,...,a2n (1≤ai≤n).

It is guaranteed that each integer from 1 to n occurs exactly twice in a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

### Output

For each test case, output a single integer — the maximum possible score.

### Example

#### Input

```
6
1
1 1
2
1 2 1 2
2
1 2 2 1
3
1 1 2 3 3 2
3
1 2 3 3 2 1
4
1 2 3 4 1 2 3 4
```

#### Output

```
4
10
16
20
36
28
```

### Note

In the second test case, one optimal strategy is to choose x=1 first. This deletes the subarray [1,2,1] and adds 32=9 to the score. The remaining array is [2]; choosing x=2 adds 1. The total score is 10.

In the third test case, choosing x=1 deletes the whole array and adds 42=16 to the score.

In the fourth test case, choose x=1 first and then choose x=2. The total score is 22+42=20.

In the sixth test case, choose x=2 first. This deletes the subarray [2,3,4,1,2] from the middle of the array and adds 52=25 to the score. After deleting this subarray and concatenating the remaining elements, the array becomes [1,3,4]. Choosing each of the three remaining values then adds 1, so the total score is 28.
