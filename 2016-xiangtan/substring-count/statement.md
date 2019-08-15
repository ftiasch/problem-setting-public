# Substring Query

Given a string $s_1, s_2, \dots, s_n$ of length $n$,
Bobo is going to perform $q$ operations of the following $2$ kinds:

1. to change the $i$-th character of the string (i.e. $s_i$) into $c$;
2. to query how many times does $p$ occur as substring of $s$.
That is, count the number of indices $i$ such that $1 \leq i \leq n - m + 1$ and $s_{i} s_{i + 1} \dots, s_{i + m - 1} = p_1 p_2 \dots p_m$.

Find out the result of each opeartion of the second kind.

## Input

The input contains at most $10$ sets. For each set:

The first line contains $2$ integers $n, q$
($1 \leq n \leq 5\times 10^4, 1 \leq q \leq 10^5$).

The second line contains a string $s_1 s_2\dots, s_n$ of lowercase characters.

The $i$-th of the last $q$ lines may:
1. contains an integer $k_i$ and a lowercase character $c_i$,
which denote an operation to change the $s_{k_i}$ into $c_i$
($1 \leq k_i \leq n$).
2. contains an $0$ followed by a string $p_1,p_2,\dots,p_{l_i}$ of lowercase characters,
which denote an operation to query the number of times that $p_1,p_2,\dots,p_{l_i}$ occurs as a substring ($l_i \geq 1, \sum_i l_i \leq 5\times 10^4$).

## Output

For each operation of second kind in each set,
an integer denotes the number of substrings.

<!--SAMPLES-->
