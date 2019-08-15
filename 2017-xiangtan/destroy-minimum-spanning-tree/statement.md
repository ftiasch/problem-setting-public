# Roads

In ICPCCamp, there are $n$ towns conveniently labeled with $1, 2, \dots, n$ and $m$ bidirectional roads planned to be built.
The $i$-th road will be built between cities $a_i$ and $b_i$ with cost $c_i$.
The builders in ICPCCamp will build the $(n - 1)$ roads with the least total cost to connect any of two cities directly or indirectly.

Bobo, the mayor of ICPCCamp is going to remove some of the roads from the construction plan.
He would like to know the minimum number of roads to be removed to *strictly increase* the total cost.

Note that the total cost is considered as $+\infty$ if no valid $(n - 1)$ roads exist after removing. It is also counted as "total cost strictly increases".

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains two integers $n$ and $m$.
The $i$-th of the following $m$ lines contains $a_i, b_i, c_i$.

* $2 \leq n \leq 50$
* $n - 1 \leq m \leq n^2$
* $1 \leq a_i, b_i \leq n$
* $1 \leq c_i \leq 10^9$
* Any two cities will be connected if all $m$ roads are built.
* The sum of $n$ does not exceed $10^3$.

## Output

For each case, output an integer which denotes the result.

<!--SAMPLES-->
