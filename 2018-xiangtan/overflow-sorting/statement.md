# Sorting

Bobo has $n$ tuples $(a_1, b_1, c_1), (a_2, b_2, c_2), \dots, (a_n, b_n, c_n)$.
He would like to find the lexicographically smallest permutation $p_1, p_2, \dots, p_n$ of $1, 2, \dots, n$ such that for $i \in \{2, 3, \dots, n\}$ it holds that
$$\frac{a_{p_{i - 1}} + b_{p_{i - 1}}}{a_{p_{i - 1}} + b_{p_{i - 1}} + c_{p_{i - 1}}} \leq \frac{a_{p_i} + b_{p_i}}{a_{p_i} + b_{p_i} + c_{p_i}}.$$

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains an integer $n$.
The $i$-th of the following $n$ lines contains $3$ integers $a_i$, $b_i$ and $c_i$.

## Output

For each test case, print $n$ integers $p_1, p_2, \dots, p_n$ seperated by spaces.
DO NOT print trailing spaces.

## Constraint

* $1 \leq n \leq 10^3$
* $1 \leq a_i, b_i, c_i \leq 2 \times 10^9$
* The sum of $n$ does not exceed $10^4$.

<!--SAMPLES-->
