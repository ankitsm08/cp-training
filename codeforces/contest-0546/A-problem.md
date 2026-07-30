---
contest_id: 546
index: A
title: A. Soldier and Bananas
rating: 800
tags:
  - brute force
  - implementation
  - math
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/546/A
---

A soldier wants to buy $w$ bananas in the shop. He has to pay $k$ dollars for the first banana, $2k$ dollars for the second one and so on (in other words, he has to pay $i \cdot k$ dollars for the $i$-th banana).

He has $n$ dollars. How many dollars does he have to borrow from his friend soldier to buy $w$ bananas?

### Input

The first line contains three positive integers $k,n,w$ ($1 \le k,w \le 1000$, $0 \le n \le 10^{9}$), the cost of the first banana, initial number of dollars the soldier has and number of bananas he wants.

### Output

Output one integer — the amount of dollars that the soldier must borrow from his friend. If he doesn't have to borrow money, output $0$.

### Examples

#### Input

```
3 17 4
```

#### Output

```
13
```
