# Determinant

Bobo learned the definition of determinant $\mathrm{det}(A)$ of matrix $A$ in ICPCCamp. He also knew determinant can be computed in $O(n^3)$ using Gaussian Elimination.

Bobo has an $n \times n$ matrix $B$ he would like to find $\mathrm{det}(B_{i,j})$ modulo $(10^9+7)$ for all $i, j \in \{1, 2, \dots, n\}$
where $B_{i, j}$ is the matrix after removing the $i$-th row and $j$-th column from $B$.

It is guaranteed that the each column sum of $B$ is a multiple of $(10^9+7)$.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains an integer $n$.
The $i$-th of following $n$ lines contains $n$ integers $B_{i, 1}, B_{i, 2}, \dots, B_{i, n}$.

* $2 \leq n \leq 500$
* $0 \leq B_{i, j} < 10^9 + 7$
* The sum of $n$ does not exceed $5000$.

## Output

For each case, output $n$ rows where the $i$-th row contains $n$ integers $\mathrm{det}(B_{i,1}), \mathrm{det}(B_{i, 2}), \dots, \mathrm{det}(B_{i, n})$ modulo $(10^9+7)$.

<!--SAMPLES-->
