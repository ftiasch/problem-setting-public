# Use FFT

Bobo computes the product $P(x) \cdot Q(x) = c_0 + c_1 x + \dots + c_{n + m} x^{n + m}$ for two polynomials $P(x) = a_0 + a_1 x + \dots + a_n x^n$ and $Q(x) = b_0 + b_1 x + \dots + b_m x^m$.
Find $(c_{L} + c_{L + 1} + \dots + c_{R})$ modulo $(10^9+7)$ for given $L$ and $R$.

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains four integers $n$, $m$, $L$, $R$.

The second line contains $(n+1)$ integers $a_0, a_1, \dots, a_n$.

The third line contains $(m+1)$ integers $b_0, a_1, \dots, a_m$.


## Output

For each test case, print an integer which denotes the reuslt.

<!--SAMPLES-->

## Constraint

* $1 \leq n, m \leq 5\times 10^5$
* $0 \leq L \leq R \leq n + m$
* $0 \leq a_i, b_i \leq 10^9$
* Both the sum of $n$ and the sum of $m$ do not exceed $10^6$.
