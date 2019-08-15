# From Tree to Graph

Bobo has a tree of $n$ vertices numbered with $0, 1, \dots, (n - 1)$.
He subsequently adds $m$ edges between vertex $x_i$ and $\mathrm{LCA}(x_i, y_i)$
where $\mathrm{LCA}(x_i, y_i)$ is the vertex lying on the unique tree path between vertex $x_i$ and $y_i$ and closest to the vertex $0$.

Let the graph obtained by adding the edges $\{(x_1, \mathrm{LCA}(x_1, y_1)), (x_2, \mathrm{LCA}(x_2, y_2)), \dots, (x_i, \mathrm{LCA}(x_i, y_i))\}$ to the tree be $G_i$,
and $f_i(u)$ be the number of connected components after the removal of vertex $u$ from $G_i$.
Bobo knows that for $i \in \{0, 1, 2, \dots, m\}$
$$z_i = f_i(0) \oplus f_i(1) \oplus \dots \oplus f_i(n - 1).$$
($\oplus$ denotes xor.)

Given $a, b, x_0, y_0$, he also knows that for $i \in \{1, 2, \dots, m\}$,

* $x_i = (a \cdot x_{i - 1} + b \cdot y_{i - 1} + z_{i - 1}) \bmod n$,
* $y_i = (b \cdot x_{i - 1} + a \cdot y_{i - 1} + z_{i - 1}) \bmod n$.

Help him to find $x_m$, $y_m$.

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains six integers $n$, $m$, $a$, $b$, $x_0$, $y_0$.
The $i$-th of the following $(n - 1)$ lines contains two integers $u_i$ and $v_i$, which denotes the tree edge between vertex $u_i$ and $v_i$.

## Output

For each test case, print two integers which denote $x_m$, $y_m$.

## Constraint

* $2 \leq n \leq 5000$
* $1 \leq m \leq n^2$
* $0 \leq a, b, x_0, y_0, u_i, v_i < n$
* The sum of $n$ does not exceed $25,000$.

<!--SAMPLES-->

## Note

The following table shows the detailed value for the second sample.
\begin{tabular}{|c|c|c|c|c|c|c|c|c|c}
    \hline
    $i$ & $x_i$ & $y_i$ & $\mathrm{LCA}(x_i, y_i)$ & $f_i(0)$ & $f_i(1)$ & $f_i(2)$ & $f_i(3)$ & $z_i$ \\
    \hline
    0   & 2     & 0     & 0                        & 1        & 2        & 2        & 1        & 0 \\
    1   & 2     & 0     & 0                        & 1        & 1        & 2        & 1        & 3 \\
    2   & 1     & 3     & 1                        & 1        & 1        & 2        & 1        & 3 \\
    \hline
\end{tabular}
