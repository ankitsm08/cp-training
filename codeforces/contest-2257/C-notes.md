**TL;DR:** Put a camera just above every dam except the highest one closest to the root, $m-1$ cameras and we can tell every dam apart.

We have tree rooted at $1$. The beaver walks straight down from the root, so any camera on its road will be seen. For a dam $v$ we see exactly the cameras on the road from root to $v$.

We pick $r$ as the dam with smallest depth from the root. Depth is $dep[1]=1$, $dep[i]=dep[p_i]+1$, one pass works because $p_i < i$. Then we put a camera on the edge into every dam $a \ne r$. That is $m-1$ cameras. If $m=1$ we put $0$.

Why we can tell every dam apart:

- If two dams sit on different branches, each road contains its own camera but not the others, so the seen set differs.
- If one dam $x$ sits on the road to another dam $y$, then $y$ sees its own camera plus the camera at $x$, while $x$ sees only its own. Deeper always sees one more.
- The highest dam $r$ has no camera on its road, it sees nothing. Every other dam sees at least its own camera, so $r$ is distinct too.

A tiny chain helps: root -> $r$ -> $x$ -> $y$. We see $\{\}$ at $r$, $\{x\}$ at $x$, $\{x,y\}$ at $y$. All different.

Why we cant do with fewer than $m-1$:

With $k$ cameras there are only $k+1$ different things we can see, empty, first camera, first two, and so on, because everything is on a single downward road. To get $m$ different answers we need $k+1 \ge m$, so $k \ge m-1$. Our $m-1$ meets the bound, so it is optimal.

We just scan for $r$ and output all other $a_i$. Order does not matter.

- Time: $O(n + m)$ per test, $O(n)$ total over all tests
- Space: $O(n)$
