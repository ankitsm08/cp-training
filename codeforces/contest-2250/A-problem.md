---
contest_id: 2250
index: A
title: A. Threshold Movement
rating: Unrated
tags:
  - implementation
  - math
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2250/A
---

There are $n+2$ positions numbered from $0$ to $n+1$. Initially, position $i$ contains an element of weight $w_i$ for every $1\le i\le n$, while positions $0$ and $n+1$ are empty.

You choose an integer $k$. Then every element moves exactly once, simultaneously:

- If $w_i \lt k$, the element at position $i$ moves to position $i-1$;
- If $w_i \gt k$, the element at position $i$ moves to position $i+1$;
- If $w_i=k$, the entire movement process fails immediately.

An integer $k$ is perfect if the movement does not fail and, upon completion, every position from $1$ to $n$ contains exactly one element.

Determine whether a perfect integer $k$ exists.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains one integer $n$ ($1\le n\le 100$).

The second line of each test case contains $n$ integers $w_1,w_2,\ldots,w_n$ ($1\le w_i\le 10^9$).

### Output

For each test case, print "YES" if a perfect integer $k$ exists, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

### Example

#### Input

```
6
1
7
2
3 1
2
2 1
4
9 1 7 2
4
9 8 7 1
6
1000000000 1 9 2 8 3
```

#### Output

```
NO
YES
NO
YES
NO
YES
```

### Note

In the first test case, the only element either leaves position $1$ or has weight equal to $k$, so no suitable integer exists.

In the second test case, choose $k=2$. The element of weight $3$ moves right and the element of weight $1$ moves left, leaving one element in each position.

In the third test case, keeping both positions occupied would require $1 \lt k \lt 2$, which is impossible for an integer $k$.

In the fourth test case, $k=5$ is suitable: the elements at positions $1$ and $3$ move right, while those at positions $2$ and $4$ move left. Upon completion, every position from $1$ to $4$ contains exactly one element.

In the fifth test case, the element at position $2$ must move left, requiring $k \gt 8$, while the element at position $3$ must move right, requiring $k \lt 7$. These requirements are incompatible.

In the sixth test case, choose $k=4$. All elements at odd positions move right and all elements at even positions move left, so every position from $1$ to $6$ contains one element afterwards.
