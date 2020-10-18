# Minimum Spanning Tree

Bobo has an undirected connected graph with $n$ vertices and $m$ edges, where the $i$-th edge is associated with two parameters $a_i$ and $b_i$.

Let $f(x)$ be the sum of weights of the edges in the minimum spanning tree when the weight of the $i$-th edge is $a_i + b_i \cdot x$, your task is to calculate the value of $\min(f(l), f(l+1), \ldots, f(r))$.

## Input

The input consists of several test cases terminated by end-of-file. For each test case:

The first line contains four integers $n$, $m$, $l$ and $r$, indicating the number of vertices, the number edges and the range of $x$.

For the next $m$ lines, the $i$-th line contains four integers $u_i$, $v_i$, $a_i$ and $b_i$ , indicating that the $i$-th edge connects vertices $u_i$ and $v_i$ and the parameters of the $i$-th edge. It is guaranteed that the graph is connected.

* $2 \le n \le 10^5$
* $n - 1 \le m \le 2 \times 10^5$
* $0 \le l \le r \le 10^6$
* $1 \le u_i, v_i \le n$, $u_i \ne v_i$
* $1 \le a_i \le 10^6$
* $-10^6 \le b_i \le 10^6$
* The sum of $n$ does not exceed $10^6$.
* The sum of $m$ does not exceed $2 \times 10^6$.

## Output

For each test case, print an integer which denotes the result.

<!--SAMPLES-->