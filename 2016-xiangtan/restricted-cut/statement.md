# TC or CF

There are $n$ contests going to be held in the upcoming year.
However, the committee keeps debating whether the contest is of TC (Thinking Creatively) style or CF (Coding Fast) style.

The committee knows in advance that there are $m$ contestants who take part in *exactly two* contests.
The $i$-th contestant will join the $a_i$-th contest and then the $b_i$-th contest.
Note that contests are held in parallel so that there may exist two contestants $i$ and $j$ where $a_i = b_j, b_i = a_j$.

If the $i$-th contestant takes a TC-style contest then a CF-style contest,
he or she will feel $c_i$ points of unhappiness. Otherwise he will not feel unhappy.
Therefore, the committee will decides the types of contests according to the following $3$ rules:

* There are at least $3$ TC-style contests, and the first contest ($1$-st) should be TC-style.
* There are also at least $3$ CF-style contests, and the last contest ($n$-th) should be CF-style.
* The total unhappiness of contestants is minimized.

## Input

The input contains at most $30$ sets. For each set:

The first line contains $2$ integers $n, m$ ($6 \leq n \leq 50, 0 \leq m \leq 500$).

The $i$-th of the following $m$ lines contains $3$ integers $a_i, b_i, c_i$ ($1 \leq a_i, b_i \leq n, a_i \neq b_i, 1 \leq c_i \leq 1000$).

## Output

For each set, an integer denotes the minimum of total unhappiness.

<!--SAMPLES-->
