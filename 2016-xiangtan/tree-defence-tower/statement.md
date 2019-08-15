# Defense Tower

In ICPCCamp, there are $n$ cities and $(n - 1)$ (bidirectional) roads between cities.
The $i$-th road is between the $a_i$-th and $b_i$-th cities.
It is guaranteed that cities are connected.

In the $i$-th city, there is a defense tower with power $p_i$.
The tower protects all cities with a road directly connected to city $i$.
However, the tower in city $i$ does not protect city $i$ itself.

Bobo would like to destroy all defense towers.
When he tries to destroy the tower in city $i$, any not-destroyed tower protecting city $i$ will deal damage whose value equals to its power to Bobo.

Find out the minimum total damage Bobo will receive if he chooses the order to destroy the towers optimally.

## Input

The input contains at most $30$ sets. For each set:

The first line contains an integer $n$ ($1 \leq n \leq 10^5$).

The second line contains $n$ integers $p_1, p_2, \dots, p_n$ ($1 \leq p_i \leq 10^4$).

The $i$-th of the last $(n - 1)$ lines contains $2$ integers $a_i, b_i$ ($1 \leq a_i, b_i \leq n$).

## Output

For each set, an integer denotes the minimum total damage.

<!--SAMPLES-->
