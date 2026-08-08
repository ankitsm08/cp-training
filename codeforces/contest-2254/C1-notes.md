**TL;DR:** each move shifts a char by 2, so `#ones` on even indices and on odd indices are each invariant - feasible iff both match.

Check per-parity signed difference of ones between `a` and `b`; accept iff both are `0`.

- Time: $O(n)$
- Space: $O(1)$