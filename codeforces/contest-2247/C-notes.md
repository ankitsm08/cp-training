**TL;DR:** $a = b$ -> $0$, $a = 0^n$ or $b = 1^n$ -> $-1$, otherwise $D = \{j : a_j \ne b_j\}$ is flippable iff $\sum_{j \in D} a_j$ odd -> $1$ else $2$.

We flip a subsequence $S$ only when $\sum_{j \in S} cur_j$ odd. To reach $b$ we must flip exactly $D$.

If $a = b$ we need $0$ moves.

If $a = 0^n$ no $S$ has odd sum, so we can never move. If $a \ne b$ this is $-1$.

If $b = 1^n$ and $a \ne 1^n$, any $S$ that could give $1^n$ would have to be $S = \{j : cur_j = 0\}$, but then $\sum_{j \in S} cur_j = 0$ even so not allowed. Any other $S$ leaves a $0$. So $1^n$ is unreachable from a non-$1^n$ array, also $-1$.

Assume now $\sum a_j > 0$ and $\sum b_j < n$ and $a \ne b$, so feasible. Flipping $D$ itself works iff

$$\sum_{j \in D} a_j = |\{j : a_j = 1, b_j = 0\}| \text{ odd}$$

then answer is $1$. We just test $D$.

Otherwise the sum is even and $1$ is impossible, we show $2$ always works.

- If $D$ contains at least two indices with $a_j = 1$, split $D$ into two parts each containing an odd number of those $1$s. Each part has odd sum so both flips are allowed and their xor is $D$.

- Else every $j \in D$ has $a_j = 0$ (so $D$ is only $0 \to 1$). Because we are not in the $-1$ cases there exist $i$ with $a_i = b_i = 0$ and $k$ with $a_k = b_k = 1$. Do

$$S_1 = D \cup \{i,k\},\quad S_2 = \{i,k\}$$

Then $\sum_{S_1} a_j = 1$ odd (only $k$ contributes), after $S_1$ we have $a'_i = 1, a'_k = 0$, so $\sum_{S_2} a'_j = 1$ odd as well, and $S_1 \oplus S_2 = D$. So $a \to a' \to b$ in two moves.

Thus otherwise answer is $2$.

- Time: $O(n)$
- Space: $O(n)$
