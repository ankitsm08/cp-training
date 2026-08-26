**TL;DR:** Keep one per equal-run gives `runs` without swap, one adjacent swap can add at most $2$ by taking a second copy from a run of length $\ge 2$ and swapping it past its neighbor.

We compress by runs. Let $c$ be $a$ with consecutive equal colors merged, $|c| = runs$. Adjacent entries of $c$ are different by construction, so taking one element from each run is valid and optimal without a swap.

```py
runs = 1 + count(a[i] != a[i-1] for i = 1..n-1)
```

Any subsequence can contain at most one element from a run unless two equal elements become separated after the single adjacent swap. So to beat $runs$ we must pick two elements from some run $r$ where the original run length is at least $2$. Those two copies are adjacent in the kept subsequence before the swap, creating exactly one bad adjacency `x,x`. One adjacent swap can fix at most one such bad pair if the pair touches an endpoint, or two if it sits in the middle and we swap one copy of the pair with a neighbor from the next run.

Hence the answer is $runs$, $runs+1$, or $runs+2$

Small $n$:

- Case $n \le 2$: answer is $runs$ directly.
- Case $n = 3$:
  - if $runs = 1$ (all equal) answer $1$
  - otherwise we can always arrange $3$ as $[x,x,y] \to [x,y,x]$ or $[x,y,y] \to [y,x,y]$ with one swap.

For $n \ge 4$ we scan windows of size $4$ in the original $a$ to detect where an extra copy can be justified:

- Gain $+2$:  
  Interior double-double. Pattern $a[i]=a[i+1]$, $a[i+1]\ne a[i+2]$, $a[i+2]=a[i+3]$, $a[i]\ne a[i+3]$, i.e. $[x,x,y,y]$ with $x \ne y$.  
  We keep both copies of both runs and swap the middle two: $[x,x,y,y] \to [x,y,x,y]$. This is the only way to gain $2$, needs two consecutive runs each of length $\ge 2$ with different colors.  
  Example $[1,1,2,2]$

- Gain $+1$ at a border:  
  $[x,y,y]$ at the start with $x \ne y$ ($a[0]\ne a[1]$ and $a[1]=a[2]$) or symmetrically $[y,y,x]$ at the end. We take two from the length $\ge 2$ run and swap the border element past one copy: $[x,y,y] \to [y,x,y]$.  
  Example $[1,2,2,1]$ start, $[1,2,1,1]$ end

- Gain $+1$ interior single-double:  
  $a[i]=a[i+1]$, $a[i+1]\ne a[i+2]$, $a[i+2]\ne a[i+3]$, $a[i]\ne a[i+3]$ i.e. $[x,x,y,z]$ with $x\ne y$, $y\ne z$, $x\ne z$; or symmetrically $[x,y,z,z]$ with $x\ne z$.  
  We take two from the double run and swap one copy with the immediate single neighbor, need the double color to differ from the second neighbor so the swapped sequence has no new collision.  
  Example $[1,1,2,3] \to [1,2,1,3]$ requires $1 \ne 3$, and $[1,2,3,3] \to [1,3,2,3]$ requires $1 \ne 3$

If none of these windows exist we cannot add any extra copy, answer stays $runs$. The scan is linear and checks patterns in priority $+2$ then $+1$, any match is sufficient for maximality.

- Time: $O(n)$
- Space: $O(1)$ auxiliary
