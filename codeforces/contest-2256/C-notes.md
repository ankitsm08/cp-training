**TL;DR:** Control follows the holder's team: Red steers potatoes sitting on odd seats, Blue on even seats, and Red's score = number of Blue seats occupied at the end. Type each Blue seat ("box") by its two neighboring cells; the value is the initial count of patterns "box and clockwise neighbor both hold" plus "box empty, counter-clockwise seat holds" - independent of $k$.

**Setup:** seats $R_j = 2j-1$, $B_j = 2j$; box $j$ is seat $B_j$. Each eliminated Blue holds exactly one potato, so Red's score $X$ = boxes occupied after round $k$, scores sum to `total`, game is zero-sum. A pass needs the target empty at round start; only the front of an occupied block can advance.

Type each box at time $t$:

a) $B_j=1, R_{j+1}=1$  
b) $B_j=0, R_j=1$  
c) $B_j=0, R_j=0$  
d) $B_j=1, R_{j+1}=0$

Potential $\Phi = \#(a) + \#(b)$

**Lemma:** $\Phi$ never increases under any play.  
Blue's only real move is ejecting from a $(d)$-box - an $(a)$-box exit is blocked, $(b)$/$(c)$ hold nothing. Ejecting turns box $j$ $(d) \to (c)$, losing $1$, but the landed potato upgrades box $j+1$, $(c) \to (b)$ or $(d) \to (a)$, gaining $1$: net $0$. So even Blue's own moves cant raise $\Phi$.  
Red's only real move is injecting from a gate into a $(b)$-box: $(b) \to (a)$ stays $1$, $(b) \to (c)$ drops to $0$, and freeing $R_j$ downgrades box $j-1$ from $(a)$ to $(d)$ if it was $(a)$. Never gains.

**Upper bound:** Blue ejects every $(d)$-box every round, final round included.  
Boxes occupied at the end are then at most: $(a)$-boxes as of round $k-1$ - their exit is blocked at round start, and blocking reads the round-start config, so the occupant cant leave during round $k$ - plus injections during round $k$, each needing an empty box and occupied gate at round start: at most $\#(b)(k-1)$ of them. Hence

$$X(k) \le \Phi(k-1) \le \Phi(k-2) \le \ldots \le \Phi(0)$$

**Lower bound:** park and strike.  
For every initial $(a)$-box, the blocker at $R_{j+1}$ never moves => occupant trapped forever.  
For every initial $(b)$-box, the gate potato sits at $R_j$ through round $k-1$, then passes in during round $k$ - legal whether the box is empty at that round start (we walk in) or occupied (the occupant either stays, or leaves during round $k$ while our simultaneous entry lands). Box ends occupied either way.  
One parked soldier can double as blocker for box $j-1$ and gate for box $j$; stepping into box $j$ during round $k$ doesnt release box $(j-1)$'s occupant, since his exit was blocked at round start.

Value $= \Phi(0)$ exactly, independent of $k$; print Red $= \Phi(0)$, Blue $=$ total $- \Phi(0)$. Code loops odd string indices (Blue seats, since index $i$ = leprechaun $i+1$).

- Time: $O(n)$
- Space: $O(1)$
