# Infinity

In ICPCCamp, candies are in different sizes.
There are $f(i)$ (defined below) distinct types of candies of $i$ grams where
$$f(i) = \left\{\begin{array}{ll}
a_i & \mathrm{for}\ 1 \leq i \leq n \\
\sum_{j = 1}^n c_j \cdot f(i - j) & \mathrm{for}\ i > n \\
\end{array}\right..$$

Bobo would like to buy some candies whose sum of weight is $m$ grams and align them in a row.
Find the number of different ways modulo $(10^9+7)$.
Note that two ways are different if they differs in the types or in the order of alignment.

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains two integers $n$ and $m$.
The second line contains $n$ integers $a_1, a_2, \dots, a_n$.
The third line contains $n$ integers $c_1, c_2, \dots, c_n$.

## Output

For each test case, print an integer which denotes the result.

## Constraint

* $1 \leq n \leq 50$
* $1 \leq m \leq 10^9$
* $0 \leq a_i, c_i \leq 10^9$
* The number of test cases does not exceed $10$.

<!--SAMPLES-->
