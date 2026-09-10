---
contest_id: 2260
index: B
title: B. Monocarp and Projects
rating: Unrated
tags:
  - math
  - number theory
time_limit: 2 seconds
memory_limit: 512 megabytes
url: https://codeforces.com/problemset/problem/2260/B
---

Monocarp runs a company. Consider the work of his company over the next $k$ months. In the first month, the company has $x$ employees, not counting Monocarp himself, and $y$ projects need to be completed. In each next month, both the number of employees and the number of projects increase by $1$.

In other words, in month $i$ ($0 \le i \lt k$), the company has $x+i$ employees and needs to complete $y+i$ projects.

In each month, Monocarp distributes the projects among the employees. Each employee must receive the same number of projects, and each project can be assigned to at most one employee. Monocarp completes all unassigned projects himself. He always chooses a distribution that makes him complete as few projects as possible.

In particular, if in some month there are $a$ employees and $b$ projects, then Monocarp assigns exactly $\left\lfloor \frac{b}{a} \right\rfloor$ projects to each employee, and he completes $b \bmod a$ projects himself.

Find the total number of projects that Monocarp will complete himself over the next $k$ months.

### Input

The first line contains an integer $t$ — the number of test cases ($1 \le t \le 10^4$).

Each test case consists of one line containing three integers $x$, $y$, and $k$ ($1 \le x \le y \le 10^6$; $1 \le k \le 10^{12}$).

Additional constraint on the input:

- the sum of $y$ over all test cases does not exceed $10^6$.

### Output

For each test case, output one integer — the total number of projects that Monocarp will complete himself over $k$ months.

### Example

#### Input

```
7
1 1 1
3 10 2
3 8 6
7 20 1
10 25 100
8 36 17
1 999900 1000000000000
```

#### Output

```
0
4
18
6
1425
110
999898177699820694
```

### Note

In the first test case, the only employee completes the only project, so Monocarp is left with no projects.

In the second test case, in the first month, $10$ projects are distributed among $3$ employees: each gets $3$ projects, and Monocarp completes $1$ project. In the second month, $11$ projects are distributed among $4$ employees: each gets $2$ projects, and Monocarp completes $3$ projects. The answer is $1 + 3 = 4$.

In the third test case, the number of projects completed by Monocarp in the six months is $2$, $1$, $0$, $5$, $5$, and $5$, respectively. Their sum is $2 + 1 + 0 + 5 + 5 + 5 = 18$.
