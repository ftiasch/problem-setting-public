# Determinant

Bobo learned the definition of determinant $\mathrm{det}(A)$ of matrix $A$ in ICPCCamp. He also knew determinant can be computed in $O(n^3)$ using Gaussian Elimination.

Bobo has an $(n - 1) \times n$ matrix $B$ he would like to find $\mathrm{det}(B_{j})$ modulo $(10^9+7)$ for all $j \in \{1, 2, \dots, n\}$
where $B_{j}$ is the matrix after removing the $j$-th column from $B$.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains an integer $n$.
The $i$-th of following $n$ lines contains $n$ integers $B_{i, 1}, B_{i, 2}, \dots, B_{i, n}$.

* $2 \leq n \leq 200$
* $0 \leq B_{i, j} < 10^9 + 7$
* The sum of $n$ does not exceed $2000$.

## Output

For each case, output $n$ integers which denote the result.

<!--SAMPLES-->

## Note

For the second sample,
$$\mathrm{det}(B_1) = \mathrm{det} \begin{bmatrix}
    2 & 0 \\
    3 & 1 \\
\end{bmatrix} = 2.$$
