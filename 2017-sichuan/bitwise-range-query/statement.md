# Broken Counter

Bobo made a very long sequence of numbers $(a_1, a_2, \dots, a_n)$ in ICPCCamp where $a_i = f(i)$ and
$$ f(i) = \left\{\begin{array}{ll}
    1 & i \leq 0 \\
    A \cdot f(i - 1) + B \cdot f(i - m) & i > 0
\end{array}\right..$$

Now he wants to ask $q$ questions where the $i$-th question is to compute the sum of $a_{l_i}, a_{l_i + 1}, \dots, a_{r_i}$.
Unfortunately, the only tool which Bobo can utilize is an old broken $4$-bit counter.
While trying to answer the $i$-th question, Bobo will set the counter to $0$, and add numbers to the counter in the order of $a_{l_i}, a_{l_i + 1}, \dots, a_{r_i}$.

As the counter is broken, adding the number $a$ to a counter holding value $x$ yields $[(x \oplus w_i) + a]\ \mathrm{mod}\ 16$.
Note that ``$\oplus$'' stands for bitwise exclusive or (XOR).

Bobo would like to know the final result.

*Special Note*: The time limit is tight so that some optimization might be necessary. Try to solve the problem as late as possible.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains five integers $n$, $m$, $A$, $B$, $q$.
The $i$-th of the following $q$ lines contains three integers $l_i$, $r_i$ and $w_i$.

* $1 \leq n \leq 10^8$
* $2 \leq m \leq 10^5$
* $0 \leq A, B, w_i < 16$
* $1 \leq q \leq 13$
* $1 \leq l_i \leq r_i \leq n$
* The number of test cases does not exceed $10$.

## Output

For each question, output an integer which denotes the result.

<!--SAMPLES-->
