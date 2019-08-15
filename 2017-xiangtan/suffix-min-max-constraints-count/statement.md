# Similar Subsequence

For given sequence $A = (a_1, a_2, \dots, a_n)$, a sequence $S = (s_1, s_2, \dots, s_n)$ has *shape* $A$ if and only if:

* $s_i = \min\{s_i, s_{i + 1}, \dots, s_n\}$ for all $a_i = 0$;
* $s_i = \max\{s_i, s_{i + 1}, \dots, s_n\}$ for all $a_i = 1$.

Given sequence $B = (b_1, b_2, \dots, b_m)$, Bobo would like to know the number of subsequences of length $n$ which have *shape* $A$ modulo $(10^9+7)$.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains two integers $n$ and $m$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

The thrid line contains $m$ integers $b_1, b_2, \dots, b_m$.

* The number of test cases does not exceed $10$.
* $1 \leq n \leq 20$
* $1 \leq m \leq 500$
* $0 \leq a_i \leq 1$
* $1 \leq b_i \leq m$
* $b_1, b_2, \dots, b_m$ are distinct.

## Output

For each case, output an integer which denotes the number of subsequences modulo $(10^9+7)$.

<!--SAMPLES-->

## Note

For the first sample, all three subsequences of length $2$ are of shape $A$.
