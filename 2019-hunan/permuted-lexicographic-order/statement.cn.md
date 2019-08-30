# 字典序

对于序列 $A = (a_1, a_2, \dots, a_m)$ 和  $B = (b_1, b_2, \dots, b_m)$，定义 $A$ 的字典序比 $B$ 小，记作 $A < B$ ，当且仅当存在 $1 \leq p \leq m$ 使得 $a_p < b_p$ 且对于所有的 $1 \leq i < p$ 都有 $a_i = b_i$. 进一步地，定义 $A \leq B$ 当且仅当 $A < B$ 或者 $A = B$.

Bobo 有一个 $n$ 行 $m$ 列的矩阵 $C$. 他想找字典序最小的 $1, 2, \dots, m$ 的排列 $\sigma_1, \sigma_2, \dots, \sigma_m$, 使得 $S_1 \leq S_2 \leq \dots \leq S_n$，其中 $S_i = (C_{i, \sigma_1}, C_{i, \sigma_2}, \dots, C_{i, \sigma_m})$.

## 输入格式

输入文件包含多组数据，请处理到文件结束。

每组数据的第一行包含两个整数 $n$ 和 $m$.

接下来 $n$ 行，其中第 $i$ 行包含 $m$ 个整数 $C_{i, 1}, C_{i, 2}, \dots, C_{i, m}$.

* $1 \leq n, m \leq 2000$
* $1 \leq C_{i, j} \leq 10^9$
* $n \times m$ 的总和不超过 $10^7$

## 输出格式

对于每组数据，如果有解，输出 $m$ 个整数，表示字典序最小的 $\sigma_1, \sigma_2, \dots, \sigma_m$. 否则输出 `-1`.

<!--SAMPLES-->
