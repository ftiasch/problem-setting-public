# Modulo Nine

Bobo has a decimal integer $\overline{a_1 a_2 \dots a_n}$, possibly with leading zeros. He knows that for $m$ ranges $[l_1, r_1], [l_2, r_2], \dots, [l_m, r_m]$, it holds that $a_{l_i} \times a_{l_i + 1} \times \dots \times a_{r_i} \bmod 9 = 0$.
Find the number of valid integers $\overline{a_1 a_2 \dots a_n}$, modulo $(10^9+7)$.

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains two integers $n$ and $m$.

The $i$th of the following $m$ lines contains two integers $l_i$ and $r_i$.

* $1 \leq n, m \leq 50$
* $1 \leq l_i \leq r_i \leq n$
* There are at most $100$ test cases.

## Output

For each test case, print an integer which denotes the result.

<!--SAMPLES-->
