# Dynamic Graph

Bobo has a directed acyclic graph (DAG) with $n$ nodes and $m$ edges whose nodes is conveniently labeled with $1, 2, \dots, n$.
All nodes are white initially.

Bobo performs $q$ operations subsequently.
The $i$-th operation is to change the node $v_i$ from white to black or vice versa.

After each operation, he would like to know the number of pairs of nodes $(u, v)$ that $u, v$ are both white and there exists a path from $u$ to $v$ passing only white nodes.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains three integers $n, m$ and $q$.

The $i$-th of the following $m$ lines contains two integers $a_i, b_i$.

The $i$-th of the last $q$ lines contains an integer $v_i$.

* $2 \leq n \leq 300$
* $1 \leq m \leq \frac{n(n - 1)}{2}$
* $1 \leq q \leq 300$
* $1 \leq a_i < b_i \leq n$
* $1 \leq v_i \leq n$
* The number of tests cases does not exceed $10$.

## Output

For each operation, output an integer which denotes the number of pairs.

<!--SAMPLES-->
