# Pair-Pair

Bobo is tired of all kinds of hard LIS (Longest Increasing Subsequence) problems,
so he decides to make himself some easier one.

Bobo has $n$ pairs $(a_1, b_1), (a_2, b_2), \dots, (a_n, b_n)$
where $1 \leq a_i, b_i \leq m$ holds for all $i$.
He defines $f(i, j)$ be the length of longest increasing subsequence of sequence $\{a_i, b_i, a_j, b_j\}$.

It's clear that $1 \leq f(i, j) \leq 4$.
Bobo would like to know $g(k)$ which is the number of pairs $(i, j)$ where $f(i, j) = k$.

Note that a sequence labeled with $\{i_1, i_2, \dots, i_k\}$ is an increasing subsequence of $\{a_1, a_2, \dots, a_n\}$ only if:

* $1 \leq i_1 < i_2 < \dots < i_k \leq n$
* $a_{i_1} < a_{i_2} < \dots < a_{i_k}$

## Input

The input contains at most $30$ sets. For each set:

The first line contains $2$ integers $n, m$ ($1 \leq n \leq 10^5, 1 \leq m \leq 10^3$).

The $i$-th of the following $n$ lines contains $2$ integers $a_i, b_i$ ($1 \leq a_i, b_i \leq m$). 

## Output

For each set, $4$ integers $g(1), g(2), g(3), g(4)$.

<!--SAMPLES-->
