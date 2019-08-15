# Strange Optimization

Bobo is facing a strange optimization problem. 
Given $n, m$, he is going to find a real number $\alpha$ such that $f(\frac{1}{2} + \alpha)$ is maximized, where $f(t) = \min_{i, j \in \mathbb{Z}} |\frac{i}{n} - \frac{j}{m} + t|$. 
Help him!

Note: It can be proved that the result is always rational.

## Input

The input contains zero or more test cases and is terminated by end-of-file. 

Each test case contains two integers $n, m$.

* $1 \leq n, m \leq 10^9$
* The number of tests cases does not exceed $10^4$.

## Output

For each case, output a fraction $p/q$ which denotes the result.

<!--SAMPLES-->

## Note

For the first sample, $\alpha = 0$ maximizes the function.
