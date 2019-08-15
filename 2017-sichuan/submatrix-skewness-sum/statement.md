# Skewness

Bobo has a matrix $A$ with $n$ rows and $n$ columns.

For submatrix with upper-left corner $(x_1, y_1)$ and lower-right corner $(x_2, y_2)$ ($1 \leq x_1 \leq x_2 \leq n, 1 \leq y_1 \leq y_2 \leq n$),
he defined its *skewness* $S(x_1, y_1, x_2, y_2) = \left(\sum_{i = x_1}^{x_2} \sum_{j = y_1}^{y_2} A_{i, j}\right)^3$.

Bobo would like to know the sum of *skewness* of all submatrices modulo $(10^9+7)$.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains an integer $n$.

The $i$-th of following $n$ lines contains $n$ integers $A_{i, 1}, A_{i, 2}, \dots, A_{i, n}$.

* $1 \leq n \leq 1000$
* $0 \leq A_{i, j} \leq 10^9$
* The number of test cases does not exceed $10$.

## Output

For each case, output an integer which denotes the sum.

<!--SAMPLES-->
