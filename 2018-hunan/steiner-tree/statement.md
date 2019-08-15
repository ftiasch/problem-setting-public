# Steiner Tree

Bobo has a connected undirected simple graph with $n$ vertices and $m$ edges.
The vertices are numbered by $1, 2, \dots, n$ conveniently, and the $i$-th edge has weight $c_i$.

For each integer $k \in [2, n]$, Bobo would like to choose a subset of edges to connect the vertices $1, 2, \dots, k$ with each other.
The minimum sum of weight of valid subsets is denoted as $f(k)$.

Find the value of $f(2), f(3), \dots, f(n)$.

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains two integers $n$ and $m$.

The $i$-th of the following $m$ lines contains $3$ integers $a_i$, $b_i$ and $c_i$ which denote the edge between vertices $a_i$ and $b_i$ with weight $c_i$.

## Output

For each test case, print $(n - 1)$ integers which denote $f(2), f(3), \dots, f(n)$.

<!--SAMPLES-->

## Constraint

* $2 \leq n \leq 26$
* $n - 1 \leq m \leq \frac{n(n - 1)}{2}$
* $1 \leq a_i, b_i \leq n$
* $1 \leq c_i \leq 1000$
* The number of test cases does not exceed $100$.
* The number of test cases with $n > 8$ does not exceed $5$.
