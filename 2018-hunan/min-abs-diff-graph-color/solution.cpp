#include <bits/stdc++.h>

using LL = long long;

void update(LL& x, LL a)
{
    x = std::min(x, a);
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
        }
        std::vector<int> ngh(n);
        for (int i = 0, a, b; i < m; ++ i) {
            scanf("%d%d", &a, &b);
            a --, b --;
            ngh[a] |= 1 << b;
            ngh[b] |= 1 << a;
        }
        std::sort(a.begin(), a.end());
        std::vector<LL> dp(1 << n, std::numeric_limits<LL>::max());
        dp[0] = 0;
        for (int msk = 0; msk < 1 << n; ++ msk) {
            int i = __builtin_popcount(msk);
            for (int j = 0; j < n; ++ j) {
                if (~msk >> j & 1) {
                    int low = __builtin_popcount(ngh[j] & ~msk);
                    int high = __builtin_popcount(ngh[j] & msk);
                    update(dp[msk | 1 << j], dp[msk] + 1LL * (high - low) * a[i]);
                }
            }
        }
        std::cout << dp[(1 << n) - 1] << "\n";
    }
}
