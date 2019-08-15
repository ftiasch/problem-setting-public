#include <bits/stdc++.h>

const int N = 51;
const int MOD = 1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int a[N], c[N];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++ i) {
            scanf("%d", a + i);
        }
        for (int i = 1; i <= n; ++ i) {
            scanf("%d", c + i);
        }
        std::vector<int> f(m + 1);
        for (int i = 1; i <= m; ++ i) {
            if (i <= n) {
                f[i] = a[i];
            } else {
                for (int j = 1; j <= n; ++ j) {
                    update(f[i], 1LL * f[i - j] * c[j] % MOD);
                }
            }
        }
        std::vector<int> conv(m + 1);
        conv[0] = 1;
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= i; ++ j) {
                update(conv[i], 1LL * conv[i - j] * f[j] % MOD);
            }
        }
        printf("%d\n", conv[m]);
    }
}
