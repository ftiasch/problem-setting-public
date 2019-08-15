# Higher $h$-index

The $h$-index of an author is the largest $h$ where he has at least $h$ papers with citations not less than $h$.

Bobo has no papers and he is going to publish some subsequently.
If he works on a paper for $x$ hours, the paper will get $(a \cdot x)$ citations, where $a$ is a known constant.
It's clear that $x$ should be a positive integer.
There is also a trick -- one can cite his own papers published earlier.

Given Bobo has $n$ working hours, find the maximum $h$-index of him.

## Input

The input consists of several test cases and is terminated by end-of-file.

Each test case contains two integers $n$ and $a$.

## Output

For each test case, print an integer which denotes the maximum $h$-index.

## Constraint

* $1 \leq n \leq 10^9$
* $0 \leq a \leq n$
* The number of test cases does not exceed $10^4$.

<!--SAMPLES-->

## Note

For the first sample, Bobo can work $3$ papers for $1$ hour each.
With the trick mentioned, he will get papers with citations $2, 1, 0$. Thus, his $h$-index is $1$.

For the second sample, Bobo can work $2$ papers for $1$ and $2$ hours respectively. He will get papers with citations $1 + 1, 2 + 0$. Thus, his $h$-index is $2$.
