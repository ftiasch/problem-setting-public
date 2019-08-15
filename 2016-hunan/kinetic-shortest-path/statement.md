# Toll

In ICPCCamp, there are $n$ cities and $m$ unidirectional roads between cities.
The $i$-th road goes from the $a_i$-th city to the $b_i$-th city.
For each pair of cities $u$ and $v$, there is at most one road from $u$ to $v$.

As traffic in ICPCCamp is becoming heavier, toll of the roads also varies.
At time $t$, one should pay $(c_i \cdot t + d_i)$ dollars to travel along the $i$-th road.

Bobo living in the $1$-st city would like to go to the $n$-th city.
He wants to know the average money he must spend at least if he starts from city $1$ at $t \in [0, T]$.
Note that since Bobo's car is super-fast, traveling on the roads costs him **no time**.

Formally, if $f(t)$ is the minimum money he should pay from city $1$ to city $n$ at time $t$,
Bobo would like to find $$\frac{\int_0^{T} f(t) \mathrm{d}t}{T}.$$

## Input

The input contains at most $30$ sets. For each set:

The first line contains $3$ integers $n, m, T$ ($2 \leq n \leq 10, 1 \leq m \leq n(n - 1), 1 \leq T \leq 10^4$).

The $i$-th of the following $m$ lines contains $4$ integers $a_i, b_i, c_i, d_i$
($1 \leq a_i, b_i \leq n, a_i \neq b_i, 0 \leq c_i, d_i \leq 10^3$).

It is guaranteed that Bobo is able to drive from city $1$ to city $n$.

## Output

A floating number denotes the answer.
It will be considered correct if its absolute or relative error does not exceed $10^{-6}$.

<!--SAMPLES-->
