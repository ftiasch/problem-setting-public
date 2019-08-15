# Partial Sum

Bobo has a integer sequence $a_1, a_2, \dots, a_n$ of length $n$.
Each time, he selects two ends $0 \leq l < r \leq n$ and add $|\sum_{j = l + 1}^r a_j| - C$ into a counter which is zero initially.
He repeats the selection for *at most* $m$ times.

If each end can be selected at most once (either as left or right), find out the maximum sum Bobo may have.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains three integers $n$, $m$, $C$.
The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

* $2 \leq n \leq 10^5$
* $1 \leq 2m \leq n + 1$
* $|a_i|, C \leq 10^4$
* The sum of $n$ does not exceed $10^6$.

## Output

For each test cases, output an integer which denotes the maximum.

<!--SAMPLES-->
