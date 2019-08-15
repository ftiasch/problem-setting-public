# Roads

In ICPCCamp there were $n$ towns conveniently numbered with $1, 2, \dots, n$
connected with $m$ roads.

Bobo would like to know the number of ways to keep only $(n - 1)$ roads so that the towns remain connected.

Note that the towns are connected if and only any two cities reach each other.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains two integers $n$ and $m$.

The $i$-th of the following $m$ lines contains two integers $a_i$ and $b_i$ which denotes a road between cities $a_i$ and $b_i$.

* $1 \leq n \leq 10^5$
* $n < m < n + 100$
* $1 \leq a_i, b_i \leq n$
* The towns are connected with $m$ roads.
* The number of test cases does not exceed $10$.

## Output

For each test case, output an integer which denotes the number of ways modulo $(10^9 + 7)$.

<!--SAMPLES-->
