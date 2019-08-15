# Longest Increasing Subsequence

Bobo learned how to compute Longest Increasing Subsequence (LIS) in $O(n \log n)$ in ICPCCamp.

For those who did not attend ICPCCamp as Bobo,
recall $\mathrm{LIS}(a_1, a_2, \dots, a_n)$ is defined as $f[1]^2 \oplus f[2]^2 \oplus \dots \oplus f[n]^2$ where $\oplus$ denotes the exclusive-or (XOR) and $f$ is calculated as follows.
```
for i in [1, 2, ..., n]
  f[i] = 1
  for j in [1, 2, ..., i - 1]
    if a[j] < a[i] then
      f[i] = max(f[i], f[j] + 1)
```

Given sequence $A = (a_1, a_2, \dots, a_n)$, Bobo would like to find $\mathrm{LIS}(B_1), \mathrm{LIS}(B_2), \dots, \mathrm{LIS}(B_n)$
where $B_i$ is the sequence after removing the $i$-th element from $A$.

## Input

The input contains zero or more test cases and is terminated by end-of-file. For each test case:

The first line contains an integer $n$.
The second line contains $n$ integers $a_1, a_2, \dots, a_n$.

* $2 \leq n \leq 5000$
* $1 \leq a_i \leq n$
* The number of test cases does not exceed $10$.

## Output

For each case, output $n$ integers which denote $\mathrm{LIS}(B_1), \mathrm{LIS}(B_2), \dots, \mathrm{LIS}(B_n)$.

<!--SAMPLES-->
