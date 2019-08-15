#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>

typedef long long Long;

int main()
{
    int n;
    scanf("%d", &n);
    std::vector<int> low(n), high(n);
    int m = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", &low.at(i), &high.at(i));
        m = std::max(m, high.at(i) + 1);
    }
    std::vector<Long> result(n + 1);
    std::vector<int> order(n);
    std::iota(order.begin(), order.end(), 0);
    do {
        std::vector<Long> ways(m);
        for (int x = low.at(order.at(0)); x <= high.at(order.at(0)); ++ x) {
            ways.at(x) = 1;
        }
        for (int i = 1; i < n; ++ i) {
            std::vector<Long> new_ways(m);
            int lo = low.at(order.at(i));
            int hi = high.at(order.at(i));
            Long sum = 0;
            for (int x = 0; x < m; ++ x) {
                if (lo <= x && x <= hi) {
                    new_ways.at(x) = sum;
                    if (order.at(i) < order.at(i - 1)) {
                        new_ways.at(x) += ways.at(x);
                    }
                }
                sum += ways.at(x);
            }
            ways.swap(new_ways);
        }
        std::vector<int> dp(n, 1);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < i; ++ j) {
                if (order.at(j) < order.at(i)) {
                    dp.at(i) = std::max(dp.at(i), dp.at(j) + 1);
                }
            }
        }
        int lis = *std::max_element(dp.begin(), dp.end());
        for (int x = 0; x < m; ++ x) {
            result.at(lis) += ways.at(x);
        }
    } while (std::next_permutation(order.begin(), order.end()));
    for (int i = 1; i <= n; ++ i) {
        std::cout << result.at(i) << " \n"[i == n];
    }
}
