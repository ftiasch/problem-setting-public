# String Commutativity

Bobo has $n$ strings $s_1, ..., s_n$, and he would like to find the number of pairs $i < j$ where $s_i + s_j = s_j + s_i$.

Note that $a + b$ means the concatenation of the string $a$ and $b$, i.e., writing the string $a$ first, and the string $b$ second.

## Input

The input consists of several test cases terminated by end-of-file.

The first line of each test case contains an integer $n$. The $i$-th of the following $n$ lines contains a string $s_i$.

* $1 \leq n \leq 10^5$
* $|s_i| \leq 10^6$, $s_i$ contains only lower case characters.
* The sum of strings does not exceed $5 \times 10^6$.

## Output

For each test case, print an integer which denotes the result.

<!--SAMPLES-->

