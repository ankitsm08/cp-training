**TL;DR:** Each giant needs $a_1+n$ and $b_1+m$ chips to fall, Bea chips first so she wins ties.

Think of each range as steps going down. The beaver stands on one step and the opponent chips it down by $1$ each turn. To hop to the next step, the current step must be chipped to just below the next step.

If $a_i$ and $a_{i+1}$ are two neighbour heights, we need $a_i - a_{i+1} + 1$ chips to make $a_{i+1} >$ current. The next step is untouched so its height is still $a_{i+1}$. For the last hill there is no hop, we just chip it to $0$, so $a_n$ chips.

Add it up and everything in the middle cancels:

$$H_a = (a_1-a_2+1)+(a_2-a_3+1)+\dots + a_n = a_1 + n -1$$

Similarly $H_b = b_1 + m -1$. Only the first height and the count of hills matter, we dont need the rest of the arrays. Tiny check: $4,3,2,1$ needs $2+2+2+1=7$ which is $4+4-1$.

Who falls first? Bea chips at steps $0,2,4,\dots$, Ver at $1,3,5,\dots$. Ver would fall after his $H_b$-th chip at time $2H_b-1$, Bea after $2H_a$. So Ver falls earlier iff $H_b \le H_a$, i.e. $b_1+m \le a_1+n$. Bea moves first, so equal means Bea wins.

Hence we output $1$ iff $a_1+n \ge b_1+m$ else $2$. Implementation reads only $a_1,b_1$ and throws away the rest.

- Time: $O(n + m)$ per test to read, $O(1)$ work otherwise
- Space: $O(1)$
