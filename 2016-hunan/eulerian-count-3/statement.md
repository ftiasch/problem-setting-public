# Three Capitals

In ICPCCamp, there are only three capitals -- *Alpha*, *Beta* and *Gamma*.
There are also $a$ bidirectional roads between capitals *Alpha* and *Beta*,
$b$ roads between *Alpha* and *Gamma*, and $c$ roads between *Beta* and *Gamma*.

Bobo lives in capital *Alpha* and would like to travel around ICPCCamp.
He will start from capital *Alpha*, travel along each road exactly once, and return back to capital *Alpha*.

It is clear that Bobo has many plans to choose from.
He would like to find out the number of different plans, modulo $(10^9+7)$.

Note that two plans $A$ and $B$ are considered different only if there exists an $i$ where the $i$-th traveled road in plan $A$ is different from the $i$-th road in plan $B$.

## Input

The input contains at most $30$ sets. For each set:

The first line contains $3$ integers $a, b, c$ ($1 \leq a, b, c \leq 10^5$).

## Output

For each set, an integer denotes the number of different ways modulo $(10^9+7)$.

<!--SAMPLES-->
