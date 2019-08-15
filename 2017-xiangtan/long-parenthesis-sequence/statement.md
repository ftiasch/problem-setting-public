# Parentheses

Bobo has a very long sequence divided into $n$ consecutive groups.
The $i$-th group consists of $l_i$ copies of character $c_i$ where $c_i$ is either "`(`" or "`)`".

As the sequence may not be valid parentheses sequence, Bobo can change a character in the $i$-th group from "`(`" to "`)`" (and vice versa) with cost $d_i$.
He would like to know the minimum cost to transform the sequence into a valid one.

Note:

- An empty string is valid.
- If $S$ is valid, $(S)$ is valid.
- If $U, V$ are valid, $UV$ is valid.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains an integer $n$.
The $i$-th of the following $n$ lines contains $l_i, c_i, d_i$.

* $1 \leq n \leq 10^5$
* $1 \leq l_1 + l_2 + \dots + l_n \leq 10^9$
* $l_1 + l_2 + \dots + l_n$ is even.
* $1 \leq d_i \leq 10^9$
* The sum of $n$ does not exceed $10^6$.

## Output

For each case, output an integer which denotes the result.

<!--SAMPLES-->

## Note

For the first sample, Bobo should change only the character in the second group.

For the second sample, Bobo should change half of characters in both groups.
