**TL;DR:** Same parity-class invariant as C1; min ops = sum of running $|\text{balance}|$ per parity class, where $\text{balance} = \text{\#ones(a)} - \text{\#ones(b)}$ left to right.

Each op moves a char exactly one step (2 positions) on its own parity lattice. Crossing the gap between adjacent same-parity cells costs 1 op. At the boundary after cell $i$, $|\text{balance}|$ ones must cross, so cost = $\sum |\text{balance}|$.

Impossible iff some class ends with nonzero balance; output `-1`.

- Time: $O(n)$
- Space: $O(1)$
