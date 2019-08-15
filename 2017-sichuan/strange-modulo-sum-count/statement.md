# Strange Prime

Bobo finds a strange prime $P = 10^{10} + 19$ in ICPCCamp,
and he decides to write $n$ integers $x_1, x_2, \dots, x_n$ whose sum is a multiple of $P$, while $x_i$ should satisfy $0 \leq x_i < P - a_i$ for given $a_1, a_2, \dots, a_n$.

Bobo would like to know the number of different ways to write $x_1, x_2, \dots, x_n$ modulo $(10^9+7)$.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains an integer $n$.
The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

* $1 \leq n \leq 10^5$
* $0 \leq a_i \leq 10^5$
* The sum of $n$ does not exceed $10^6$.


## Output

For each case, output an integer which denotes the number of different ways.

<!--SAMPLES-->
