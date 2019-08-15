#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    int n;
    scanf("%d", &n);
    std::vector<int> low(n), high(n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", &low.at(i), &high.at(i));
    }
    std::vector<long long> result(n + 1);
    std::function<void(int, std::vector<int>)> dfs = [&](int i, std::vector<int> seq)
    {
        if (i < n) {
            for (int x = low.at(i); x <= high.at(i); ++ x) {
                seq.push_back(x);
                dfs(i + 1, seq);
                seq.pop_back();
            }
        } else {
            std::vector<int> dp(n, 1);
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < i; ++ j) {
                    if (seq.at(j) < seq.at(i)) {
                        dp.at(i) = std::max(dp.at(i), dp.at(j) + 1);
                    }
                }
            }
            int lis = *std::max_element(dp.begin(), dp.end());
            result.at(lis) ++;
        }
    };
    dfs(0, {});
    for (int i = 1; i <= n; ++ i) {
        std::cout << result.at(i) << " \n"[i == n];
    }
}
