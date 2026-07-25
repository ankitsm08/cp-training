---
contest_id: 263
index: A
title: A. Beautiful Matrix
rating: 800
tags:
  - implementation
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/263/A
---

You've got a $5 \times 5$ matrix, consisting of $24$ zeroes and a single number one. Let's index the matrix rows by numbers from $1$ to $5$ from top to bottom, let's index the matrix columns by numbers from $1$ to $5$ from left to right. In one move, you are allowed to apply one of the two following transformations to the matrix:

1. Swap two neighboring matrix rows, that is, rows with indexes $i$ and $i+ 1$ for some integer $i$ $(1 \le i< 5)$.
2. Swap two neighboring matrix columns, that is, columns with indexes $j$ and $j+ 1$ for some integer $j$ $(1 \le j< 5)$.

You think that a matrix looks beautiful, if the single number one of the matrix is located in its middle (in the cell that is on the intersection of the third row and the third column). Count the minimum number of moves needed to make the matrix beautiful.

### Input

The input consists of five lines, each line contains five integers: the $j$-th integer in the $i$-th line of the input represents the element of the matrix that is located on the intersection of the $i$-th row and the $j$-th column. It is guaranteed that the matrix consists of $24$ zeroes and a single number one.

### Output

Print a single integer — the minimum number of moves needed to make the matrix beautiful.

### Examples

#### Input

```
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
```

#### Output

```
3
```

#### Input

```
0 0 0 0 0
0 0 0 0 0
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
```

#### Output

```
1
```
