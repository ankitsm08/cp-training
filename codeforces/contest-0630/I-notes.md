**TL;DR:** one block of $n$ equal cars is the only maximal run possible ($2n - 2$ slots cant host two disjoint $n$-blocks), so count its placements by position (edge vs interior), forcing both neighbors to differ from the block.

Block start runs over $1..n-1$; its two border cars (where they exist) must differ from the block's make, or the block would not be exactly $n$.

Case edge: start $1$ or $n-1$.  
Free slots count: $2n - 2 - n - 1 = n - 3$.
$$2 \text{ sides} \times 4 \text{ makes} \times 3 \text{ (inner neighbor)} \times 4^{n-3} = 24 \cdot 4^{n-3}$$

Case middle ($n - 3$ starts), both borders differ:  
Free slots count: $2n - 2 - n - 2 = n - 4$.
$$(n-3) \cdot 4 \cdot 3^2 \cdot 4^{n-4} = 9(n-3) \cdot 4^{n-3}$$

Sum:
$$24 \cdot 4^{n-3} + 9(n-3) \cdot 4^{n-3} = 3(3n-1) \cdot 4^{n-3} = 3(3n-1) \cdot 2^{2n-6}$$

The forced-different borders cap every other run well below $n$ (at most $n-2$ in the edge case, $n-3$ in the middle), so no overcount and the "exactly $n$" requirement holds. Each counted config has a unique run of length $n$, so no double counting across cases.

Check $n=3$:  
$3 \cdot 8 \cdot 1 = 24$

Up to $n = 30$:  
$3 (3 \cdot 30 - 1) \cdot 2^{2 \cdot 30 - 6} < 2^{63}$ -- fits in `long long`

- Time: $O(1)$
- Space: $O(1)$
