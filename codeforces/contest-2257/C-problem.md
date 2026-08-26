---
contest_id: 2257
index: C
title: C. Spying on the Beaver
rating: 1200
tags:
  - constructive algorithms
  - dfs and similar
  - dsu
  - graphs
  - trees
time_limit: 2 seconds
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2257/C
---

You are given a rooted tree [*1] with $n$ vertices, numbered from $1$ to $n$. The vertex numbered $1$ is the root of the tree. The Beaver, initially located at the root, travels through the tree to one of the beaver dams located at the vertices numbered $a_1, \ldots, a_m$.

You need to determine which of these $m$ vertices the Beaver went to. To do this, you can place cameras on any edges of the tree. If the Beaver traverses an edge with a camera on it, you will see this. For clarity, we assume that after all the Beaver's movements, you will receive a sequence of edges with cameras in which the Beaver was observed passing through the corresponding edge.

Since cameras are expensive, it is necessary to use the minimum number of them sufficient to uniquely determine the Beaver's destination. You are required to state the minimum necessary number of cameras $k$ and the edges on which they should be placed.

[*1] A rooted tree is a tree where one vertex is special and called the root.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 2 \cdot 10^4$). The description of the test cases follows.

In the first line of each test case, there is a single integer $n$ ($2 \le n \le 10^5$).

The second line contains $n-1$ integers $p_2, \ldots, p_n$ — the parents of the vertices from the $2$nd to the $n$th ($1 \le p_i \lt i$; $2 \le i \le n$).

The third line contains a single integer $m$ — the number of vertices containing beaver dams ($1 \le m \le n$).

In the fourth line, there are $m$ integers $a_1, \ldots, a_m$ — the numbers of these vertices ($1 \le a_i \le n$; $1 \le i \le m$). All $a_i$ are distinct.

It is guaranteed that the sum of $n$ across all test cases does not exceed $10^5$.

### Output

For each test case, output exactly one line. First, output the number $k$ — the minimum required number of cameras, and then, in the same line, for each of the $k$ edges connecting the vertices $u$ and $p_u$, where cameras need to be installed, output the vertex number $u$.

If there are multiple answers, you can output any one of them.

### Example

#### Input

```
4
2
1
1
1
3
1 1
3
2 3 1
3
1 2
2
2 3
6
1 2 2 1 1
3
5 3 1
```

#### Output

```
0
2 2 3
1 3
2 2 5
```

### Note

In the first test case, we do not need to install any cameras because there is only one dam in the tree, and the Beaver will definitely go there.

In the second test case, it is necessary to place a camera on each edge because there is a dam located at each vertex.

In the third test case, the dams are located in two adjacent vertices, so by placing a camera on the edge between these vertices, we can uniquely determine which one the Beaver went to.
