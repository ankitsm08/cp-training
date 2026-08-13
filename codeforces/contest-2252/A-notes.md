**TL;DR:** Shield only helps if we trigger it as late as possible. Play a maximal prefix with no two equal neighbors, then dump the leftover run; all but the run's first card deal $0$.

Reorder freely, so the only cost is the tail after the shield fires. We build the longest prefix whose adjacent cards are pairwise distinct, then append the surplus cards consecutively. The first card of that tail triggers the shield but still deals full damage; the rest deal $0$.

Let the mode value $m$ appear $c$ times, the other values $n - c$ times.

- Case $c \le n - c + 1$: alternate `m x m x ... m`, using $n - c + 1$ copies of $m$ with the others as separators. Whole deck stays distinct-adjacent, answer $= \sum a_i$.
- Case $c > n - c + 1$: same alternating prefix consumes $n - c + 1$ copies of $m$; the surplus $c - (n - c) - 1$ copies of $m$ pile up at the tail. The run's first card still hits, so lost damage is

$$(c - (n - c) - 1 - 1) \cdot m = (c - (n - c) - 2) \cdot m$$

The surplus is necessarily copies of the mode (it is the only value with enough frequency to overflow), so the wasted per-card is exactly $m$.

$$\text{ans} = \sum a_i - \max(0, c - (n - c) - 2) \cdot m$$

- Time: $O(n \log n)$ (sort to find mode)
- Space: $O(1)$
