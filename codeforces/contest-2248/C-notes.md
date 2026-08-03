**TL;DR:** answer = $2n + \max$ total weight of pairwise disjoint value-intervals, where interval $[l, r]$ has weight $w = \text{len}^2 - \text{len} = \text{len}(\text{len} - 1)$. Weighted interval scheduling, DP over right endpoints.

Each operation deletes a contiguous segment of the current array, so the operation segments partition all $2n$ original positions, and score is $\sum \text{len}^2$ over segments.

Accounting: an element deleted alone (singleton op) scores $1$, so the all-singletons baseline is $2n$. Choosing a full interval of length $\text{len}$ merges $\text{len}$ singleton ops into one op that scores $\text{len}^2$ - we lose those $\text{len}$ baseline points and gain $\text{len}^2$. Net weight of the interval:

$$w = \text{len}^2 - \text{len} = \text{len}(\text{len} - 1)$$

Total score = $2n + \sum w$ over chosen intervals; the leftover elements stay singletons, $2n - \sum \text{len}$ of them.

A non-singleton segment must be the full original interval $[\text{first}_x, \text{last}_x]$ of its chosen value $x$: the occurrences sit at the segment ends, and any position inside the span that was deleted earlier would break contiguity. So the segments of length $\ge 2$ are exactly a set of pairwise disjoint intervals.

Unchosen values need no extra handling: if neither occurrence of $y$ lands inside a chosen interval, both survive and $y$ must be deleted whole - contradiction, so it is itself chosen. Hence every unchosen $y$ is a singleton (one occurrence absorbed) or fully absorbed.

Pick disjoint intervals maximizing total weight. Classic DP: sort by right endpoint, sweep $j = 1..2n$,

$$dp[j] = \max\left(dp[j-1],\ \max_{r = j - 1} \left(dp[l] + w\right)\right)$$

$dp[j]$ covers positions $< j$; an interval $(l, r)$ ends exactly at $j - 1$, starts after prefix $dp[l]$. Answer is $2n + dp[2n]$.

Crossing intervals are never both usable - sample 2 ($[0,2]$, $[1,3]$) takes one for weight $6$, other degenerates to a singleton.

- time: $O(n \log n)$ (sorting intervals; sweep is $O(n)$)
- space: $O(n)$
