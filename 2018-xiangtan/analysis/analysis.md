---
author: 郭晓旭 (@ftiasch)
title: 题目分析
---

# A. Easy $h$-index

从大到小枚举 $h$.

<!--对于 $h$，计算 $\mathrm{cnt}_h = a_h + a_{h + 1} + \cdots + a_n = a_h + \mathrm{cnt}_{h + 1}$.-->

# B. Higher $h$-index

最优方案是各花 $1$ 小时写 $n$ 篇论文。

答案是 $\lfloor\frac{n + a}{2}\rfloor$.

# C. Just $h$-index

建立 $a_1, a_2, \dots, a_i$ 的持久化线段树 $T_i$.

询问时在 $T_r - T_{l - 1}$ 上二分，复杂度是 $O((n + q) \log n)$.

# D. Circular Coloring

预处理 $f(i, j)$ 表示把 $i$ 个球分成 $j$ 段，所有可能乘积的和。

注意到黑球和白球总是一样多段的，每组数据只需枚举段数，用预处理的 $f$ 乘一下就行。

# E. From Tree to Graph

如果维护了 dfs 树的 low 属性，就能快速算出答案。

注意到一个点的 low 至多减少 $n$ 次，所以一共的改变只有 $O(n^2)$.
用并查集找到路径上最近一个需要改的，暴力改掉就行。

# F. Sorting

`long double` 精度可能不够，直接交叉相乘需要 $6 \times (2 \times 10^9)^2 > 2^{64}$.

转化为排序 $\frac{c_i}{a_i + b_i + c_i}$，交叉相乘只需要 $3 \times (2 \times 10^9)^2 < 2^{64}$.

# G. String Transformation

`c` 不变，按照 `c` 分段。只要每段内 `a` 和 `b` 的奇偶性相同。

# H. Infinity

设答案是 $g(m)$，$g(m)$ 也是 $n$ 阶的线性递推，高斯消元解出递推式后快速幂。

# I. Longest Increasing Subsequence

设 $f_i$, $g_i$ 分别表示以点 $i$ 开始、结束的 LIS 长度，$L$ 是原来的 LIS 长度。

对于每个 $i$，找出它下一个 $0$ 后面的 $a_j$ 满足 $f_i + g_j = L$，那么当 $x$ 在 $[a_i + 1, a_j - 1]$ 的区间内时，答案是 $L+1$.

# J. Vertex Cover

考虑覆盖集的补集独立集，从大到小枚举每个点。

如果点 $v$ 在独立集内，说明它和之前选的都没边；
如果点 $v$ 不在独立集内，说明它跟之前选的至少有一条边。

# K. 2018

$2018$ 的约数只有 $4$ 个，可以算出区间内和 $2018$ 的最大公约数是 $1, 2, 1009, 2018$ 的各有几个，之后 $4 \times 4$ 枚举统计答案。
