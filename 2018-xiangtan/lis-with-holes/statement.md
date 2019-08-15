# Longest Increasing Subsequence

Bobo has a sequence $a_1, a_2, \dots, a_n$.
Let $f(x)$ be the length of longest *strictly* increasing subsequence after replacing all the occurrence of $0$ with $x$.
He would like to find $\sum_{i = 1}^n i \cdot f(i)$.

Note that the length of longest strictly increasing subsequence of sequence $s_1, s_2, \dots, s_m$ is the largest $k$
such that there exists $1 \leq i_1 < i_2 < \dots < i_k \leq m$ satisfying $s_{i_1} < s_{i_2} < \dots < s_{i_k}$.

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains an integer $n$.
The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

## Output

For each test case, print an integer which denotes the result.

## Constraint

* $1 \leq n \leq 10^5$
* $0 \leq a_i \leq n$
* The sum of $n$ does not exceed $250,000$.

<!--SAMPLES-->
