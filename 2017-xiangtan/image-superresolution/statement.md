# Super Resolution

Bobo has an $n \times m$ picture consists of black and white pixels.
He loves the picture so he would like to scale it $a \times b$ times.
That is, to replace each pixel with $a \times b$ block of pixels with the same color (see the example for clarity).

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case,

The first line contains four integers $n, m, a, b$.
The $i$-th of the following $n$ lines contains a binary string of length $m$ which denotes the $i$-th row of the original picture. Character "`0`" stands for a white pixel while the character "`1`" stands for black one.

* $1 \leq n, m, a, b \leq 10$
* The number of tests cases does not exceed $10$.

## Output

For each case, output $n \times a$ rows and $m \times b$ columns which denote the result.

<!--SAMPLES-->
