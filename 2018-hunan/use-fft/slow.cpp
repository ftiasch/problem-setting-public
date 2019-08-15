#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main()
{
    int n, m, l, r;
    while (scanf("%d%d%d%d", &n, &m, &l, &r) == 4) {
        std::vector<int> a(n + 1), b(m + 1);
        for (int i = 0; i <= n; ++ i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i <= m; ++ i) {
            scanf("%d", &b[i]);
        }
        int result = 0;
        for (int i = 0; i <= n; ++ i) {
            for (int j = 0; j <= m; ++ j) {
                if (l <= i + j && i + j <= r) {
                    result += 1LL * a[i] * b[j] % MOD;
                    if (result >= MOD) {
                        result -= MOD;
                    }
                }
            }
        }
        printf("%d\n", result);
    }
}
