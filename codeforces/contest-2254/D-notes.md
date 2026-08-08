**TL;DR:** Equal `a` values share equal shadows, and distinct `a` values have strictly increasing shadows - so every `a` value is forced by consecutive group gaps; reconstruct, verify strictness, else `-1`.

Let distinct values $a_1 < a_2 < \dots < a_k$ have counts $c_m$. All elements of value $a_m$ share shadow $S_m = \sum_{r < m} c_r a_r$, and $S$ is strictly increasing in $m$ (since $a_r \ge 1, c_r \ge 1$). Hence equal shadows group together.

Given group shadow $S_m$ and size $c_m$, the gap to the next group forces

$$a_m = \dfrac{S_{m+1} - S_m}{c_m}$$

Last group has no next shadow, so pick the smallest valid $a_k = a_{k-1} + 1$; its shadow is already the group's `b`. Valid iff $S_1 = 0$, every gap divides cleanly, and the $a_m$ stay strictly increasing; else `-1`. The values are unique, so the reconstruction is the lexicographically smallest array.

- Time: $O(n \log n)$
- Space: $O(n)$
