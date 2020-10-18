# Absolute Difference Equation

For a sequence $a_1, a_2, \ldots, a_n$, consider the following operation $f$: $f(a)=\{b_1, b_2, \ldots, b_{n-1}\}$, where $b_i=|a_i-a_{i+1}|$.

After applying the operation $f$ for $n-1$ times, denoted by $f^{n-1}(a)$, the sequence will become a single element.

Bobo has a sequence $a$ of length $n$ filled with `0`, `1` and `?`. He would like to know the number of ways modulo $(10^9+7)$ to replace `?` to `0` or `1` such that $f^{n-1}(a)=\{1\}$. 

## Input

The input consists of several test cases terminated by end-of-file. For each test case:

The first line contains a nonempty string $a$ consisting only of `0`, `1` and `?`, denoting the given sequence.

* $1 \leq |a| \leq 10^6$
* The sum of $|a|$ does not exceed $10^7$.

## Output

For each test case, print an integer which denotes the result.

<!--SAMPLES-->