# Tree Intersection

Bobo has a tree with $n$ vertices numbered by $1, 2, \dots, n$ and $(n - 1)$ edges.
The $i$-th vertex has color $c_i$, and the $i$-th edge connects vertices $a_i$ and $b_i$.

Let $C(x, y)$ denotes the set of colors in subtree rooted at vertex $x$ deleting edge $(x, y)$.

Bobo would like to know $R_i$ which is the size of intersection of $C(a_i, b_i)$ and $C(b_i, a_i)$ for all $1 \leq i \leq (n - 1)$.
(i.e. $|C(a_i, b_i) \cap C(b_i, a_i)|$)

## Input

The input contains at most 15 sets. For each set:

The first line contains an integer $n$ ($2 \leq n \leq 10^5$).

The second line contains $n$ integers $c_1, c_2, \dots, c_n$ ($1 \leq c_i \leq n$).

The $i$-th of the last $(n - 1)$ lines contains $2$ integers $a_i, b_i$
($1 \leq a_i, b_i \leq n$).

## Output

For each set, $(n - 1)$ integers $R_1, R_2, \dots, R_{n - 1}$.

<!--SAMPLES-->
