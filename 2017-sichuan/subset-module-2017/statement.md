# 2017 Revenge

Bobo has $n$ integers $a_1, a_2, \dots, a_n$.
He would like to choose some of the integers and calculate their product (the product of the empty set is defined as $1$).

Bobo would like to know the number of products whose remainder divided by $2017$ is $r$. As the exact number is too large, he only asks for the number modulo $2$.

## Input

The input contains zero or more test cases and is terminated by end-of-file.  For each case,

The first line contains two integers $n, r$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

* $1 \leq n \leq 2\times 10^6$
* $1 \leq r, a_1, a_2, \dots, a_n < 2017$
* The sum of $n$ does not exceed $2 \times 10^6$.

## Output

For each case, output an integer which denotes the parity.

<!--SAMPLES-->
