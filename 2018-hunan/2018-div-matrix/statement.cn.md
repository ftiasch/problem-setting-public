
# 2018

Bobo 想统计满足下面条件的矩阵 $A$ 的数量。

1. 矩阵 $A$ 有 $n$ 行 $m$ 列，每个元素都是正整数。第 $i$ 行第 $j$ 列的元素用 $A_{i, j}$ 表示。
2. $A_{1, 1} = 2018$.
3. 对于所有 $2 \leq i \leq n, 1 \leq j \leq m$，$A_{i, j}$ 是 $A_{i - 1, j}$ 的约数。
4. 对于所有 $1 \leq i \leq n, 2 \leq j \leq m$，$A_{i, j}$ 是 $A_{i, j - 1}$ 的约数。

因为满足条件的矩阵 $A$ 数量很多，Bobo 只想统计满足条件的矩阵数量除以 $(10^9+7)$ 的余数。

## 输入格式

输入文件包含多组数据，请处理到文件结束。

每组数据包含 $2$ 个整数 $n$ 和 $m$.

## 输出格式

对于每组数据输出 $1$ 个整数表示所求的数量除以 $(10^9+7)$ 的余数。

<!--SAMPLES-->

## 样例解释

对于第二组样例($n = 1$, $m = 2$)，满足条件的矩阵 $A$ 有 $(2018, 2018), (2018, 1009), (2018, 2), (2018, 1)$ 共 $4$ 种。

## 数据范围

* $1 \leq n, m \leq 2000$
* 数据组数不超过 $10^5$.
