---
contest_id: 2248
index: B
title: B. Merge to Match
rating: 1000
tags:
  - greedy
  - sortings
time_limit: 1.5 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2248/B
---

You are given two arrays a and b of lengths n and m, respectively. All n+m integers in these arrays are **distinct**.

You can perform the following operation on a any number of times (possibly, zero):

- Choose two elements of a with values x and y, where x≤y.
- Delete these two elements from a.
- Insert one integer z into a such that x≤z≤y.

After performing all operations, you may arrange the elements of a in any order.

Determine whether it is possible to make a equal to b.

### Input

Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains two integers n and m (1≤n,m≤2⋅105) — the lengths of the arrays a and b.

The second line contains n integers a1,a2,...,an (1≤ai≤109).

The third line contains m integers b1,b2,...,bm (1≤bi≤109).

It is guaranteed that all n+m integers in the arrays a and b are **distinct**.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

It is guaranteed that the sum of m over all test cases does not exceed 2⋅105.

### Output

For each test case, print "`YES`" if it is possible to make a equal to b, and "`NO`" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "`yEs`", "`yes`", "`Yes`", and "`YES`" will be recognized as positive responses.

### Example

#### Input

```
11
2 1
1 3
2
3 2
1 3 5
2 4
4 2
1 3 5 7
4 6
4 2
2 5 8 11
1 10
4 2
1 4 7 9
3 10
5 2
10 1 100 6 4
90 5
6 3
1 4 10 20 30 40
3 15 35
4 2
1 2 3 100
4 5
7 3
1 8 3 30 18 12 25
2 15 28
4 1
1 2 3 5
4
4 2
1 3 5 6
2 4
```

#### Output

```
YES
NO
YES
NO
NO
YES
YES
NO
YES
YES
YES
```

### Note

In the first test case, choose 1 and 3, delete them, and insert 2.

In the second test case, it can be shown that no sequence of operations can make a equal to b.

In the third test case, choose 1 and 5, delete them, and insert 4. Then, choose 3 and 7, delete them, and insert 6.

In the sixth test case, first choose 1 and 10, delete them, and insert 5. Next, choose 6 and 100, delete them, and insert 90. Finally, choose 4 and 5, delete them, and insert 5.

In the seventh test case, for the pairs (1,4), (10,20), and (30,40), delete both elements and insert 3, 15, and 35, respectively.

In the ninth test case, delete the pairs (1,3), (8,18), and (25,30) and insert 2, 15, and 28, respectively. Then, delete 12 and 15 and insert 15.

In the tenth test case, first choose 1 and 2, delete them, and insert 2. Then, choose 2 and 3, delete them, and insert 3. Finally, choose 3 and 5, delete them, and insert 4.
