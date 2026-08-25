**TL;DR:** Domino weights cancel the shared tile: $w_i = w_{i+1} \iff s_i = s_{i+2}$, so validity means each parity class strictly alternates. Answer is $0$ on any fixed distance-$2$ collision, otherwise $2^{c}$ where $c$ = number of classes consisting entirely of `?`.

Domino weight $w_i = s_i + s_{i+1} \in \{0,1,2\}$, and consecutive dominoes share tile $s_{i+1}$:

$$w_i = w_{i+1} \iff s_i + s_{i+1} = s_{i+1} + s_{i+2} \iff s_i = s_{i+2}.$$

Only distance-$2$ pairs matter - adjacent tiles never compare directly. Splitting indices by parity gives two independent chains; within a chain consecutive elements must differ. Chains dont interact.

Counting per class: if a class holds at least one fixed digit, alternation anchors it and forces every slot uniquely (propagates both directions) -> exactly $1$ completion. If the class is all `?`, both phases work -> $2$. Total $2^{c}$, $c \in \{0,1,2\}$; the modulus is decoration since the answer is at most $4$. Covers $n = 2$ too: loop body empty, one free class per `?`.

Implementation: scan left to right, keep `all_q` per class = "every char seen so far is `?`". Conflict iff $s_{i-2} \ne$ `?` and $s_{i-2} = s_i$. Once a class loses `all_q`, fill fresh `?` slots with the inverse of $s_{i-2}$ so later conflict checks see concrete digits. Fills always chain off a non-`?` anchor: if $s_{i-2}$ were still `?` while some earlier char is fixed, then $s_{i-2}$ itself was already filled at step $i-2$. So no garbage reads.

- Time: $O(n)$
- Space: $O(n)$
