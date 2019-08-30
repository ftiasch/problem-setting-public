# Parity of Tuples (Easy)

Bobo has $n$ $m$-tuple $v_1, v_2, \dots, v_n$, where $v_i = (a_{i, 1}, a_{i, 2}, \dots, a_{i, m})$. He wants to find $\mathrm{count}(x)$ which is the number of $v_i$ where $a_{i, j} \wedge x$ has odd number of ones in its binary notation for all $j$. Note that $\wedge$ denotes the bitwise-and.

Find $\sum_{x = 0}^{2^k - 1} \mathrm{count}(x) \cdot 3^x$ modulo $(10^9+7)$ for given $k$.

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains three integers $n$, $m$ and $k$.

The $i$th of the following $n$ lines contains $m$ integers $a_{i, 1}, a_{i, 2}, \dots, a_{i, m}$.

* $1 \leq n \leq 10^4$
* $1 \leq m \leq 10$
* $1 \leq k \leq 30$
* $0 \leq a_{i, j} < 2^k$.
* There are at most $100$ test cases, and at most $1$ of them have $n > 10^3$ or $m > 5$.

## Output

For each test case, print an integer which denotes the result.

<!--SAMPLES-->
