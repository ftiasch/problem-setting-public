#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

bool cmp(int x, int y)
{
    return x < y;
}

int get_sum(const std::vector<std::vector<int>>& sum, const std::pair<int, int>& x_range, const std::pair<int, int>& y_range)
{
    int x0, x1, y0, y1;
    std::tie(x0, x1) = x_range;
    std::tie(y0, y1) = y_range;
    return sum.at(x0).at(y0) - sum.at(x0).at(y1) - sum.at(x1).at(y0) + sum.at(x1).at(y1);
}

std::pair<int, int> get_range(int m, int p0, int p1, int p2, int a0, int a1)
{
    int low = 0;
    if (p0 < p2) {
        low = std::max(low, a0 + 1);
    }
    if (p1 < p2) {
        low = std::max(low, a1 + 1);
    }
    int high = m;
    if (p0 > p2) {
        high = std::min(high, a0 + 1);
    }
    if (p1 > p2) {
        high = std::min(high, a1 + 1);
    }
    return {low, high};
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<std::vector<std::vector<int>>> sum(2, std::vector<std::vector<int>>(m + 1, std::vector<int>(m + 1)));
        std::vector<std::vector<int>> a(n);
        for (int i = 0; i < n; ++ i) {
            int x, y;
            scanf("%d%d", &x, &y);
            x --;
            y --;
            a.at(i) = {x, y};
            sum.at(cmp(x, y)).at(x).at(y) ++;
        }
        for (int k = 0; k < 2; ++ k) {
            for (int i = m; i >= 0; -- i) {
                for (int j = m; j >= 0; -- j) {
                    auto& ref = sum.at(k).at(i).at(j);
                    if (i < m) {
                        ref += sum.at(k).at(i + 1).at(j);
                    }
                    if (j < m) {
                        ref += sum.at(k).at(i).at(j + 1);
                    }
                    if (i < m && j < m) {
                        ref -= sum.at(k).at(i + 1).at(j + 1);
                    }
                }
            }
        }
        std::vector<long long> result(4);
        std::vector<int> permutation(4);
        std::iota(permutation.begin(), permutation.end(), 0);
        do {
            std::vector<int> length(4, 1);
            for (int i = 0; i < 4; ++ i) {
                for (int j = 0; j < i; ++ j) {
                    if (permutation.at(j) < permutation.at(i)) {
                        length.at(i) = std::max(length.at(i), length.at(j) + 1);
                    }
                }
            }
            int contribution = *std::max_element(length.begin(), length.end());
            for (int i = 0; i < n; ++ i) {
                if (cmp(permutation.at(0), permutation.at(1)) == cmp(a.at(i).at(0), a.at(i).at(1))) {
                    int z = cmp(permutation.at(2), permutation.at(3));
                    result.at(contribution - 1) += get_sum(sum.at(z)
                    , get_range(m, permutation.at(0), permutation.at(1), permutation.at(2), a.at(i).at(0), a.at(i).at(1))
                    , get_range(m, permutation.at(0), permutation.at(1), permutation.at(3), a.at(i).at(0), a.at(i).at(1))
                    );
                }
            }
        } while (std::next_permutation(permutation.begin(), permutation.end()));
        for (int i = 0; i < 4; ++ i) {
            std::cout << result.at(i) << " \n"[i == 3];
        }
    }
}
