#include <cstdio>

const int N = 5000;
const int MOD = 1000000007;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int inv[N + 1], dp[N + 1][N + 1];

int main()
{
    inv[1] = 1;
    for (int i = 2; i <= N; ++ i) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++ i) {
        int sum0 = 0;
        int sum1 = 0;
        for (int j = 0; j <= N; ++ j) {
            dp[i][j] = (1LL * sum0 * j + MOD - sum1) % MOD;
            update(sum0, dp[i - 1][j]);
            update(sum1, 1LL * dp[i - 1][j] * j % MOD);
        }
    }
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        int result = 0;
        for (int i = 1; i <= n && i <= m; ++ i) {
            update(result, 1LL * dp[i][n] * dp[i][m] % MOD * inv[i] % MOD);
        }
        printf("%d\n", static_cast<int>(1LL * result * (n + m) % MOD));
    }
}
