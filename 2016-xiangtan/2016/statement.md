# 2016

Given a $2 \times 2$ matrix
$$A = \begin{pmatrix}
    a_{11} & a_{12} \\
    a_{21} & a_{22} \\
\end{pmatrix},$$
find $A^n$ where $A^1 = A, A^n = A \times A^{n - 1}$.
As the result may be large,
you are going to find only the remainder after division by $7$.

*Special Note*:
The problem is intended to be easy.
Feel free to think why the problem is called `2016` if you either:

1. find it hard to solve;
2. or, solved all the other problems easily.

## Input

The input contains at most $40$ sets. For each set:

The first line contains an integer $n$ ($1 \leq n < 10^{100000}$).

The second line contains $2$ integers $a_{11}, a_{12}$.

The third line contains $2$ integers $a_{21}, a_{22}$.

($0 \leq a_{ij} < 7$, $(a_{11} a_{22} - a_{12} a_{21})$ is not a multiple of $7$)

## Output

For each set, a $2 \times 2$ matrix denotes the remainder of $A^n$ after division by $7$.

<!--SAMPLES-->
