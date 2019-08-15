# Nice Trick

Given $n$ integers $a_1, a_2, \dots, a_n$, Bobo knows how to compute the *sum of triples* $$S_3 = \sum_{1 \leq i < j < k \leq n} a_i a_j a_k.$$
It follows that $$S_3 = \frac{(\sum_{1 \leq i \leq n} a_i)^3 - 3 (\sum_{1 \leq i \leq n} a_i^2)(\sum_{1 \leq i \leq n} a_i) + 2(\sum_{1 \leq i \leq n} a_i^3)}{6}.$$

Bobo would like to compute the *sum of quadrangles* $$\left(\sum_{1 \leq i < j < k < l \leq n} a_i a_j a_k a_l\right)\bmod (10^9+7).$$

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case,

The first line contains an integer $n$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

* $1 \leq n \leq 10^5$
* $0 \leq a_i \leq 10^9$
* The number of tests cases does not exceed $10$.

## Output

For each case, output an integer which denotes the result.

<!--SAMPLES-->
