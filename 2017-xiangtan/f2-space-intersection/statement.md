# Intersection

Bobo has two sets of integers $A = \{a_1, a_2, \dots, a_n\}$ and $B = \{b_1, b_2, \dots, b_n\}$.
He says that $x \in \mathrm{span}(A)$ (or $\mathrm{span}(B)$) if and only if there exists a subset of $A$ (or $B$) whose exclusive-or sum equals to $x$.

Bobo would like to know the number of $x$ where $x \in \mathrm{span}(A)$ and $x \in \mathrm{span}(B)$ hold simultaneously.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains an integer $n$.
The second line contains $n$ integers $a_1, a_2, \dots, a_n$.
The third line contains $n$ integers $b_1, b_2, \dots, b_n$.

* $1 \leq n \leq 50$
* $0 \leq a_i, b_i < 2^{60}$
* The number of test cases does not exceed $5000$.

## Output

For each case, output an integer which denotes the result.

<!--SAMPLES-->

## Note

For the second sample, $\mathrm{span}(A) = \mathrm{span}(B) = \{0, 1, 2, 3\}$.
