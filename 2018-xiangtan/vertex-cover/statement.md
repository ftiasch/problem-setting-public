# Vertex Cover

Alice and Bobo are playing a game on a graph with $n$ vertices numbered with $0, 1, \dots, (n - 1)$.
The vertex numbered with $i$ is associated with weight $2^i$.

The game is played as follows.
Firstly, Alice chooses a (possibly empty) subset of the $\frac{n(n - 1)}{2}$ edges.
Subsequently Bobo chooses a (possibly empty) subset of the $n$ vertices to *cover* the edges chosen by Alice.
An edge is *covered* if one of its two ends is chosen by Bobo.
As Bobo is smart, he will choose a subset of vertices whose sum of weights, denoted as $S$, is minimum.

Alice would like to know the number of subsets of edges where Bobo will choose a subset whose sum of weights is exactly $k$ (i.e. $S = k$), modulo $(10^9+7)$.

## Input

The input consists of several test cases and is terminated by end-of-file.

Each test case contains two integers $n$ and $k$.
For convenience, the number $k$ is given in its binary notation.

## Output

For each test case, print an integer which denotes the result.

## Constraint

* $1 \leq n \leq 10^5$
* $0 \leq k < 2^n$
* The sum of $n$ does not exceed $250,000$.

<!--SAMPLES-->
