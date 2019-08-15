# Fixed Point

Bobo has a sequence $p_1, p_2, \dots, p_n$. Initially, $p_i = i$ holds.

One day, Bobo comes up with infinite operations. The operations are described by $m$ pairs of integers $(a_1, b_1), (a_2, b_2), \dots, (a_m, b_m)$. The $i$-th operation is to reverse the elements between the $a_{(i - 1) \bmod m + 1}$-th and the $b_{(i - 1) \bmod m + 1}$-th. Note that a sequence $q_1, q_2, \dots, q_n$ becomes $q_1, \dots, q_{x - 1}, q_y, q_{y - 1}, \dots, q_x, q_{y + 1}, \dots, q_n$ after reserving the elements between the $x$-th and the $y$-th.

Bobo also has $q$ questions $k_1, k_2, \dots, k_q$. The $i$-th question is to ask the number of $i$ satisfying $p_i = i$ if he executes only the first $k_i$ operations. Answer the questions!

## Input

The input consists of several test cases and is terminated by end-of-file.

The first line of each test case contains three integers $n$, $m$ and $q$.

The $i$-th of the following $m$ lines contains $2$ integers $a_i$ and $b_i$.

The $i$-th of the last $q$ lines contains an integer $k_i$.

## Output

For each test case, print $q$ integers which denote the answers.

<!--SAMPLES-->

## Note

For the first sample, the sequence becomes $1, 4, 3, 2, 5$ after the first operation, and becomes $1, 2, 3, 4, 5$ after the second one. Thus, the answer are $3, 5$ respectively.

## Constraint

* $1 \leq n \leq 10^5$
* $1 \leq m \leq 10$
* $1 \leq q \leq 10^5$
* $1 \leq a_i \leq b_i \leq n$
* $1 \leq k_i \leq 10^9$
* The number of test cases does not exceed $5$.
