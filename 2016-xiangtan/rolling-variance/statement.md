# Rolling Variance

Bobo learnt that the *variance* of a sequence $a_1, a_2, \dots, a_n$ is
$$\sqrt{\frac{\sum_{i = 1}^n (a_i - \bar{a})^2}{n - 1}}$$
where
$$\bar{a} = \frac{\sum_{i = 1}^n a_i}{n}.$$

Bobo has a sequence $a_1, a_2, \dots, a_n$,
and he would like to find the *variance* of each consecutive subsequences of length $m$.
Formally, the $i$-th ($1 \leq i \leq n - m + 1$) rolling variance $r_i$ is the *variance* of sequence $\{a_i, a_{i + 1}, \dots, a_{i + m - 1}\}$.

## Input

The input contains at most $30$ sets. For each set:

The first line contains $2$ integers $n, m$ $(2 \leq m \leq n \leq 10^5)$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($|a_i| \leq 100$).

## Output

For each set, $(n - m + 1)$ lines with floating numbers $r_1, r_2, \dots, r_{n - m + 1}$.

Your answer will be considered correct if its absolute or relative error does not exceed $10^{-4}$.

<!--SAMPLES-->
