# Longest Common Subsequence

Bobo has a sequence $A = (a_1, a_2, \dots, a_n)$ of length $n$.
He would like to know $f(0), f(1), f(2)$ and $f(3)$ where $f(k)$ denotes the number of integer sequences $X = (x_1, x_2, x_3)$ where:

* $1 \leq x_1, x_2, x_3 \leq m$;
* The length of longest common subsequence of $A$ and $X$ is exactly $k$.

Note:

* $u$ is a subsequence of $v$ if and only if $u$ can be obtained by removing some of the entries from $v$ (possibly none).
* $u$ is common subsequence of $v$ and $w$ if and only if $u$ is subsequence of $v$ and $w$.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each case,

The first line contains two integers $n, m$.
The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

* $1 \leq n \leq 200$
* $1 \leq m, a_1, a_2, \dots, a_n \leq 10^6$
* The number of tests cases does not exceed $10$.

## Output

For each case, output four integers which denote $f(0), f(1), f(2), f(3)$.

<!--SAMPLES-->

## Note

For the second sample, $X = (3, 3, 3)$ is the only sequence that the length of longest common subsequence of $A$ and $X$ is $1$.
Thus, $f(1) = 1$.
