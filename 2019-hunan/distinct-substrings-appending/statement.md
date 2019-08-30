# Distinct Substrings

For a string $s_1, s_2, \dots, s_n$, Bobo denotes the number of its distinct substrings as $f(s_1, s_2, \dots, s_n)$. He also defines defines $h(c) = f(s_1, s_2, \dots, s_n, c) - f(s_1, s_2, \dots, s_n)$ for character $c$.

Given a string $s_1, s_2, \dots, s_n$ and $m$, find the value of
$\bigoplus_{c = 1}^{m}\left(h(c) \cdot 3^c \bmod (10^9+7)\right)$.

Note that $\oplus$ denotes the bitwise exclusive-or (XOR).

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains two integers $n$ and $m$.

The second line contains $n$ integers $s_1, s_2, \dots, s_n$.

* $1 \leq n, m \leq 10^6$
* $1 \leq s_i \leq m$
* The sum of $n$, and the sum of $m$ do not exceed $5 \times 10^6$.

## Output

For each test case, print an integer which denotes the result.

<!--SAMPLES-->

## Note

For the second test case, $h(1) = h(2) = 2, h(3) = 3$.
