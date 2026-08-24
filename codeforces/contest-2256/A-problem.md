---
contest_id: 2256
index: A
title: A. Three Numbers on the Blackboard
rating: 800
tags:
  - math
  - sortings
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2256/A
---

Rain is falling outside the Fairy Warehouse, so Chtholly, Nephren, and Ithea spend the afternoon playing a game in the common room.

Ithea writes three non-negative integers $a$, $b$, and $c$ on the blackboard.

Chtholly may perform the following operation an arbitrary number of times (possibly zero):

- Choose one of the three current integers and replace it with the sum of the other two current integers. The other two integers remain unchanged.

For example, starting from $(3,5,11)$, she can replace $11$ with $3+5$, obtaining $(3,5,8)$.

Nephren wants to know the minimum range [*1] of the three integers that Chtholly can obtain. Help her find it!

[*1] The range of a non-empty finite collection of numbers is defined as its maximum value minus its minimum value. In particular, the range of three numbers $x$, $y$, and $z$ is $\max(x,y,z)-\min(x,y,z)$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The only line of each test case contains three integers $a$, $b$, and $c$ ($0 \le a,b,c \le 10^9$) — the integers initially written on the blackboard.

### Output

For each test case, output a single integer — the minimum possible range of the three integers.

### Example

#### Input

```
6
5 5 5
4 6 9
2 3 10
0 0 7
2 3 5
20 4 5
```

#### Output

```
0
5
3
0
3
5
```

### Note

In the first test case, all three integers are already equal, so their range is $0$.

In the second test case, performing no operation gives the range $9-4=5$. It can be shown that no sequence of operations can produce a smaller range.

In the third test case, Chtholly can replace $10$ with $2+3=5$. The three integers become $(2,3,5)$, whose range is $5-2=3$.

In the fourth test case, Chtholly can replace $7$ with $0+0=0$. All three integers then become $0$.
