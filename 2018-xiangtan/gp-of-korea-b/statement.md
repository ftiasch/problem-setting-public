# Circular Coloring

Bobo considers $(n + m)$ balls arranged in a circle.
The balls are numbered with $0, 1, \dots, (n + m - 1)$ where the ball $i$ and the ball $(i + 1) \bmod (n + m)$ are adjacent.

Bobo would like to color $n$ of his balls black and $m$ of his balls white.
Bobo groups adjacent balls with same colors, and he determines the weight of the coloring as the product of the lengths of groups.

He would like to know the sum of the weight of the possible colorings, modulo $(10^9+7)$.

## Input

The input consists of several test cases and is terminated by end-of-file.

Each test case contains two integers $n$ and $m$.

## Output

For each test case, print an integer which denotes the result.

## Constraint

* $1 \leq n, m \leq 5000$
* The number of test cases does not exceed $5000$.

<!--SAMPLES-->

## Note

For the second sample, there are $10$ possible colorings (listed below).
The number followed is the corresponding weight.

* `BBWWW` ($6$)
* `BWBWW` ($2$)
* `BWWBW` ($2$)
* `BWWWB` ($6$)
* `WBBWW` ($6$)
* `WBWBW` ($2$)
* `WBWWB` ($2$)
* `WWBBW` ($6$)
* `WWBWB` ($2$)
* `WWWBB` ($6$)
