# Spanning Trees

Bobo has a string $s_1 \dots s_n$ consisting of zeros and ones, and he constructs an undirected graph $G$ with $n$ vertices $v_1, \dots, v_n$. In the graph $G$, an edge between the vertices $v_i$ and $v_j$ if and only if $i < j$ and $s_j = 1$.

Find the number of spanning trees of the graph $G$ modulo $(10^9 + 7)$.

## Input

The input consists of several test cases terminated by end-of-file.

The first line of each test case contains an integer $n$, and the second line contains a string $s_1 \dots s_n$.

* $1 \leq n \leq 10^5$
* $s_i \in \{0, 1\}$
* $s_{n - 1} = 1$
* The sum of $n$ does not exceed $10^6$.

## Output

For each test case, print an integer which denotes the result.

<!--SAMPLES-->
