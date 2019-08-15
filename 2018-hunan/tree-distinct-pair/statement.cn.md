# 买一送一

ICPCCamp 有 $n$ 个商店，用 $1, 2, \dots, n$ 编号。对于任意 $i > 1$，有从商店 $p_i$ 到 $i$ 的单向道路。
同时，商店 $i$ 出售类型为 $a_i$ 的商品。

Bobo 从商店 $1$ 出发前往商店 $i$。他要在两个不同的商店购买商品（包括商店 $1$ 和 $i$）。设他先购买的商品类型是 $x$，后购买的商品类型是 $y$，他用 $f_i$ 表示不同的有序对 $\langle x, y \rangle$ 的数量。
求出 $f_2, f_3, \dots, f_n$ 的值。


## 输入格式

输入文件包含多组数据，请处理到文件结束。

每组数据的第一行包含 $1$ 个整数 $n$.

第二行包含 $(n - 1)$ 个整数 $p_2, p_3, \dots, p_n$.

第三行包含 $n$ 个整数 $a_1, a_2, \dots, a_n$.

## 输出格式

对于每组数据输出 $(n-1)$ 个整数表示 $f_2, f_3, \dots, f_n$.

<!--SAMPLES-->

## 样例解释

对于第三个样例，当 $i = 4$ 时，可能的有序对 $\langle x, y \rangle$ 有 $\langle 1, 2 \rangle, \langle 1, 3\rangle, \langle 2, 3 \rangle, \langle 3, 2\rangle, \langle 3, 3\rangle$ 共 $5$ 种。所以 $f_4 = 5$.

## 数据范围

* $1 \leq n \leq 10^5$
* $1 \leq p_i < i$
* $1 \leq a_i \leq n$
* $n$ 的总和不超过 $5 \times 10^5$.
