# Super Fast Fourier Transform

Bobo has two sequences of integers $\{a_1, a_2, \dots, a_n\}$ and $\{b_1, b_2, \dots, b_m\}$.
He would like to find
$$\sum_{i = 1}^n\sum_{j = 1}^m \lfloor \sqrt{|a_i - b_j|} \rfloor.$$

Note that $\lfloor x \rfloor$ denotes the maximum integer does not exceed $x$,
and $|x|$ denotes the absolute value of $x$.

## Input

The input contains at most $30$ sets. For each set:

The first line contains $2$ integers $n, m$ ($1 \leq n, m \leq 10^5$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

The thrid line contains $m$ integers $b_1, b_2, \dots, b_m$.

($a_i, b_i \geq 0, a_1 + a_2 + \dots + a_n, b_1 + b_2 + \dots, b_m \leq 10^6$)

## Output

For each set,
an integer denotes the sum.

<!--SAMPLES-->
