# 4 Buttons

Bobo lives in an infinite chessboard. Initially he locates at $(0, 0)$. There are $4$ buttons.

* When the first button is pressed, Bobo moves right for at most $a$ cells.
* When the second button is pressed, Bobo moves up for at most $b$ cells.
* When the third button is pressed, Bobo moves left for at most $c$ cells.
* When the fourth button is pressed, Bobo moves down for at most $d$ cells.

Find the number of cells Bobo can reach modulo $(10^9+7)$, if he presses the buttons for no more than $n$ times.

## Input

The input consists of several test cases and is terminated by end-of-file.

Each test case contains five integers $n$, $a$, $b$, $c$ and $d$.

* $1 \leq n, a, b, c, d \leq 10^9$
* The number of test cases does not exceed $10^5$.

## Output

For each test case, print an integer which denotes the result.

<!--SAMPLES-->

## Note

For the first test case, Bobo can reach the following $11$ cells:
$(-3, 0)$, $(-2, 0)$, $(-1, 0)$, $(0, -4)$, $(0, -3)$, $(0, -2)$, $(0, -1)$, $(0, 0)$, $(0, 1)$, $(0, 2)$, $(1, 0)$.
