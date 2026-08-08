---
contest_id: 2254
index: A
title: A. Riptide
rating: Unrated
tags:
  - implementation
  - sortings
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2254/A
---

Alice, Bob, and Charlie are playing a game with tokens. They start with $a$, $b$, and $c$ tokens, respectively.

The game is played in rounds. Before the beginning of each round, they check the number of tokens everyone has:

- If any two players have the exact same number of tokens, the game immediately ends.
- Otherwise, the round begins, all three players have a strictly different number of tokens. The player with the strictly most tokens gives exactly $1$ token to the player with the strictly fewest tokens.

Given the starting tokens $a$, $b$, and $c$, determine exactly how many rounds the game will last before it ends.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^3$) — the number of test cases.

Each test case consists of a single line containing three integers $a$, $b$, and $c$ ($1 \le a, b, c \le 10$).

### Output

For each test case, output a single integer — the number of rounds the game will last before it ends.

### Example

#### Input

```
6
1 2 3
4 6 1
3 3 7
1 7 10
6 1 9
1 1 1
```

#### Output

```
1
2
0
3
3
0
```

### Note

In the first test case:

- No two players have the same number of tokens.
- Charlie has the most tokens ($3$ tokens), and Alice has the fewest tokens ($1$ token). Therefore, Charlie gives Alice a token.
- Now, Alice has $2$ tokens, Bob has $2$ tokens, and Charlie has $2$ tokens. Since there are two players (or more) with the same number of tokens, the game ends.

The game ended after $1$ round, so the answer is $1$.

In the second test case, the game is played as follows:

- Bob gives Charlie a token, now Alice has $4$ tokens, Bob has $5$ tokens, and Charlie has $2$ tokens.
- Bob gives Charlie a token, now Alice has $4$ tokens, Bob has $4$ tokens, and Charlie has $3$ tokens. Since two players have the same number of tokens, the game ends.

The game lasted $2$ rounds.

In the third test case, two players already have the same number of tokens. So the answer is $0$ since no rounds were played.
