# String Transformation

Bobo has a string $S = s_1s_2\dots s_n$ consists of letter `a`, `b` and `c`.
He can transform the string by inserting or deleting substrings `aa`, `bb` and `abab`.

Formally, $A = u \circ w \circ v$ (``$\circ$'' denotes string concatenation) can be transformed into $A' = u \circ v$ and vice versa where $u$, $v$ are (possibly empty) strings and $w \in \{\mathrm{aa}, \mathrm{bb}, \mathrm{abab}\}$.

Given the target string $T = t_1t_2\dots t_m$, determine if Bobo can transform the string $S$ into $T$.

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains a string $s_1 s_2\dots s_n$.
The second line contains a string $t_1t_2\dots t_m$.

## Output

For each test case, print `Yes` if Bobo can. Print `No` otherwise.

## Constraint

* $1 \leq n, m \leq 10^4$
* $s_1, s_2, \dots, s_n, t_1, t_2, \dots, t_m \in \{\mathrm{a}, \mathrm{b}, \mathrm{c}\}$
* The sum of $n$ and $m$ does not exceed $250,000$.

<!--SAMPLES-->

## Note

For the first sample, Bobo can transform as `ab => aababb => babb => ba`.
