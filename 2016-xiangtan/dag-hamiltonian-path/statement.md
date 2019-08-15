# Hamiltonian Path

In ICPCCamp, there are $n$ cities and $m$ directed roads between cities.
The $i$-th road going from the $a_i$-th city to the $b_i$-th city is $c_i$ kilometers long.
For each pair of cities $(u, v)$, there can be more than one roads from $u$ to $v$.

Bobo wants to make big news by solving the famous *Hamiltonian Path* problem.
That is, he would like to visit all the $n$ cities one by one so that the total distance travelled is minimized.

Formally, Bobo likes to find $n$ **distinct** integers $p_1, p_2, \dots, p_n$
to minimize $w(p_1, p_2) + w(p_2, p_3) + \dots + w(p_{n - 1}, p_n)$ where $w(x, y)$ is the length of road from the $x$-th city to the $y$-th city.

## Input

The input contains at most $30$ sets. For each set:

The first line contains $2$ integers $n, m$ ($2 \leq n \leq 10^5, 0 \leq m \leq 10^5$).

The $i$-th of the following $m$ lines contains $3$ integers $a_i, b_i, c_i$
($1 \leq a_i < b_i \leq n, 1 \leq c_i \leq 10^4$).

## Output

For each set, an integer denotes the minimum total distance.
If there exists no plan, output `-1` instead.

<!--SAMPLES-->
