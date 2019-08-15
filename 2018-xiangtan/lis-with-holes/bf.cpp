#include <bits/stdc++.h>

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
        }
        long long result = 0;
        for (int x = 1; x <= n; ++ x) {
            auto get = [&](int i) {
                return a[i] ? a[i] : x;
            };
            std::vector<int> dp(n);
            for (int i = 0; i < n; ++ i) {
                dp[i] = 1;
                for (int j = 0; j < i; ++ j) {
                    if (get(j) < get(i)) {
                        dp[i] = std::max(dp[i], dp[j] + 1);
                    }
                }
            }
            result += 1LL * x * *std::max_element(dp.begin(), dp.end());
        }
        printf("%lld\n", result);
    }
}
