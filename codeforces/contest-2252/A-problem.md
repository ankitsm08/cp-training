---
contest_id: 2252
index: A
title: A. Boss Fight
rating: Unrated
tags:
  - data structures
  - greedy
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2252/A
---

You are fighting a boss with an unknown amount of health. You have a sequence of $n$ spell cards, where the $i$-th card deals $a_i$ damage. You can rearrange your hand and play the cards in any order you choose.

The boss has an adaptive shield. If you ever play two cards in a row that deal the exact same amount of damage, the shield permanently activates. The card that triggers the shield still deals its normal damage, but all **subsequent** cards you play will deal $0$ damage.

Find the maximum total health the boss can have such that you will defeat him if you arrange and play your cards optimally.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 50$) — the number of spell cards.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 1000$) — the damage dealt by each card.

### Output

For each test case, output a single integer — the maximum total health the boss can have such that you will defeat him.

### Example

#### Input

```
4
1
100
4
10 5 10 10
5
1 2 3 4 5
6
7 7 7 7 7 7
```

#### Output

```
100
35
15
14
```

### Note

In the first test case, you have only $1$ card. You play it, dealing $100$ damage.

In the second test case, you can arrange your hand as $[10, 5, 10, 10]$. You play the first `10`. Then you play the `5`. Then you play the second `10`. Then you play the final `10`. Because you played two `10`s in a row, the shield activates. However, the card that triggers the shield still deals its normal damage. The total damage dealt is $10 + 5 + 10 + 10 = 35$.

In the third test case, all cards are distinct. You can simply play them in any order to deal the sum of their damage: $1 + 2 + 3 + 4 + 5 = 15$.

In the fourth test case, all $6$ cards deal exactly `7` damage. No matter what order you play them in, your second card will be identical to your first. The second card will trigger the shield and deal its normal damage, but the remaining $4$ cards will deal $0$ damage. The total damage dealt is $7 + 7 = 14$.
