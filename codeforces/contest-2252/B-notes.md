**TL;DR:** An alternating subsequence keeps at most one char per run, and any balanced counts within run caps are achievable; deletion alternation then forces the kept difference $k$ into $[D-1, D+1] \cap [-1, 1]$, so we maximize kept chars over (at most) three candidates for $k$.

Two facts carry the whole solution.

Fact 1 (caps): two kept chars from the same run would sit adjacent-equal in the result, so kept zeros $\le \text{runs}_0$ and kept ones $\le \text{runs}_1$.

Fact 2 (achievability): every $(p, q)$ with $p \le \text{runs}_0$, $q \le \text{runs}_1$, $|p - q| \le 1$ is realizable. If $p > q$, take the first $p$ zero-runs plus the one-runs sandwiched between them reads $0101\ldots 0$. If $p = q$, take the first $2p$ runs. If $p < q$, symmetric. The caps are the only obstruction.

Let $D = \text{zeros} - \text{ones}$ (fixed by the string) and $k = \text{kept}_0 - \text{kept}_1$ (ours to choose). The deleted counts satisfy

$$d_0 - d_1 = (\text{zeros} - \text{kept}_0) - (\text{ones} - \text{kept}_1) = D - k$$

Both must stay in $[-1, 1]$: $k$ because the kept string alternates, $D - k$ because a multiset of $d_0$ zeros and $d_1$ ones can be deleted in alternating order iff $|d_0 - d_1| \le 1$. Hence $k \in [D-1, D+1] \cap [-1, 1]$ - at most the three candidates $D - 1, D, D + 1$. Empty intersection iff $|D| > 2$, the $-1$ case: deletion imbalance is unfixable (note this is about balance, not about subsequences. A lone char is always alternating).

For a fixed $k$: $\text{kept}_0 = \text{kept}_1 + k$ and total kept $= 2\,\text{kept}_1 + k$, maximized over

$$\max(0, -k) \le \text{kept}_1 \le \min(\text{runs}_1, \text{runs}_0 - k)$$

Left bound is $\text{kept}_0 \ge 0$, right is both run caps. Best total for that $k$ is $2 \cdot \min(\text{runs}_1, \text{runs}_0 - k) + k$ whenever the interval is nonempty; answer $= n - \max_k(\text{kept})$.

Equivalent closed form (editorial bookkeeping): $\text{ans} = (n - L) + \max(0, |D - (L_0 - L_1)| - 1)$ with $L$ the run count. Keep the compressed string, then delete extra survivors to rebalance. Both reduce to the same search over $k$.

- Time: $O(n)$
- Space: $O(1)$
