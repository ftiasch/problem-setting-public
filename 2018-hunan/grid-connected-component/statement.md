# Grid

Bobo has $n \times m$ points arranged into a matrix with $n$ rows and $m$ columns. The points in the intersection of the $i$-th row and the $j$-th column is labeled with $(i, j)$.
He is going to perform $q$ operations of the following $2$ kinds.

1. Given parameters $a, b$, add edges between points $(i, j)$ and $(i, j + 1)$ for all $a \leq i \leq b$ and $1 \leq j < m$.
2. Given parameters $a, b$, add edges between points $(i, j)$ and $(i + 1, j)$ for all $1 \leq i < n$ and $a \leq j \leq b$.

Bobo would like to know the number of connected components after each operation.

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains three integers $n$, $m$ and $q$.

The $i$-th of the following $q$ lines contains three integers $t_i$, $a_i$ and $b_i$ where $t_i$ is the kind of the operation $i$ and $a_i$, $b_i$ are corresponding parameters.

## Output

For each test case, print $q$ integers which denote the number of connected components after each operation.

<!--SAMPLES-->

## Constraint

* $1 \leq n, m \leq 10^9$
* $1 \leq q \leq 10^5$
* $t_i \in \{1, 2\}$
* If $t_i = 1$, $1 \leq l_i \leq r_i \leq n$. If $t_i = 2$, $1 \leq l_i \leq r_i \leq m$.
* The sum of $q$ does not exceed $5 \times 10^5$.
