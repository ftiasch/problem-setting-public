# Highway

In ICPCCamp there were $n$ towns conveniently numbered with $1, 2, \dots, n$
connected with $(n - 1)$ roads.
The $i$-th road connecting towns $a_i$ and $b_i$ has length $c_i$.
It is guaranteed that any two cities reach each other using only roads.

Bobo would like to build $(n - 1)$ highways so that any two towns reach each using *only highways*.
Building a highway between towns $x$ and $y$ costs him $\delta(x, y)$ cents,
where $\delta(x, y)$ is the length of the shortest path between towns $x$ and $y$ using roads.

As Bobo is rich, he would like to find the most expensive way to build the $(n - 1)$ highways.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains an integer $n$.
The $i$-th of the following $(n - 1)$ lines contains three integers $a_i$, $b_i$ and $c_i$.

* $1 \leq n \leq 10^5$
* $1 \leq a_i, b_i \leq n$
* $1 \leq c_i \leq 10^8$
* The number of test cases does not exceed $10$.

## Output

For each test case, output an integer which denotes the result.

<!--SAMPLES-->
