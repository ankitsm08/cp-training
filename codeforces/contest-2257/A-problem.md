---
contest_id: 2257
index: A
title: A. Creating Abbreviations
rating: 800
tags:
  - brute force
  - strings
time_limit: 1 second
memory_limit: 256 megabytes
url: https://codeforces.com/problemset/problem/2257/A
---

The Beaver was given a set of words $S$, which initially contained $n$ words. Then he performed the following operation $m$ times:

1. The Beaver forms a sequence of one or more words from the set $S$. The same word may appear in the sequence several times. An abbreviation [*1] is formed from the resulting phrase.
2. Then the Beaver adds the resulting abbreviation to $S$ and can now use it in subsequent operations as an ordinary word.

You are given the $n$ initial words that were in the set $S$, and the set of abbreviations that the Beaver formed. Determine whether the Beaver made a mistake and whether all these abbreviations could have appeared as a result of the operation described above. Note that the abbreviations did not necessarily appear in the same order in which they are given to you.

[*1] The abbreviation of a sequence is the word produced by the first letters of the words in the sequence. For example, the sequence _birch OAK birch redwood_ produces the abbreviation BOBR.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ — the number of ordinary words and the number of abbreviations, respectively ($1 \le n, m \le 100$).

Each of the next $n$ lines contains one string $w_i$ — an ordinary word ($1 \le |w_i| \le 20$).

Each of the next $m$ lines contains one string $a_i$ — an abbreviation formed by Bobr ($1 \le |a_i| \le 20$).

All ordinary words consist of lowercase English letters, and all abbreviations consist of uppercase English letters. In each test case, all strings $w_1, w_2, \ldots, w_n, a_1, a_2, \ldots, a_m$ are pairwise distinct.

The total length of all strings over all test cases does not exceed $50\,000$.

### Output

For each test case, print "YES" if there exists a suitable order in which the given abbreviations could have appeared, and "NO" otherwise.

You may print each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

### Example

#### Input

```
4
6 4
apple
grand
banana
great
cherry
good
AG
BG
CG
ABC
1 1
apple
AA
1 2
apple
A
AA
2 2
apple
avocado
B
BA
```

#### Output

```
YES
YES
YES
NO
```

### Note

In the first test case, the order `AG`, `BG`, `CG`, `ABC` is suitable. The first three abbreviations can be created using the pairs of words `apple` and `grand`, `banana` and `great`, and `cherry` and `good`, respectively. After that, the abbreviation `ABC` can be created using the already created abbreviations `AG`, `BG`, and `CG`.

In the second test case, one can create `AA` using `apple` twice.

In the third test case, one can first create `A` using `apple`, and then create `AA` using `apple` and the already created abbreviation `A`.

In the fourth test case, it can be shown that the required order of creating the abbreviations does not exist.
