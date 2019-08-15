# Reverse

Bobo has a $n$ digits decimal number $D = d_1d_2\dots d_n$ (It may have leading zeros).

Let $R(i, j)$ denotes number $D$ with digits between the $i$-th position and $j$-th position reversed. That is, $R(i, j) = d_1\dots d_{i - 1} d_jd_{j - 1}\dots d_i d_{j + 1}d_{j + 2}\dots d_n$.

Bobo would like to find $$ \sum_{i = 1}^n \sum_{j = i}^n R(i, j) $$ modulo $(10^9+7)$.

## Input

The input contains at most $30$ sets. For each set:

The first line contains an integer $n$ ($1 \leq n \leq 10^5$).

The second line contains $n$ digits $d_1d_2\dots d_n$ $(0 \leq d_i \leq 9)$.

## Output

For each set, an integer denotes the result.

<!--SAMPLES-->
