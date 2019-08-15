#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main()
{
    int n, m, l, r;
    while (scanf("%d%d%d%d", &n, &m, &l, &r) == 4) {
        std::vector<int> a(n + 1), b(m + 1), sum(m + 2);
        for (int i = 0; i <= n; ++ i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i <= m; ++ i) {
            scanf("%d", &b[i]);
        }
        sum[m + 1] = 0;
        for (int i = m; i >= 0; -- i) {
            sum[i] = (b[i] + sum[i + 1]) % MOD;
        }
        int result = 0;
        for (int i = 0; i <= n; ++ i) {
            int low = std::max(0, l - i);
            int high = std::min(m, r - i);
            if (low <= high) {
                result += 1LL * a[i] * (sum[low] + MOD - sum[high + 1]) % MOD;
                if (result >= MOD) {
                    result -= MOD;
                }
            }
        }
        printf("%d\n", result);
    }
}
