#include <algorithm>
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

int dp[N + 1][N + 1];

int main()
{
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++ i) {
        for (int j = 0; j <= N; ++ j) {
            for (int k = 1; k <= j; ++ k) {
                update(dp[i][j], 1LL * dp[i - 1][j - k] * k % MOD);
            }
        }
    }
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        if (n > m) {
            std::swap(n, m);
        }
        int result = 0;
        for (int k = 1; k <= n; ++ k) {
            for (int x = 0; x <= n; ++ x) {
                update(result, 1LL * x * x * dp[k - 1][n - x] % MOD * dp[k][m] % MOD);
            }
            for (int x = 0; x <= m; ++ x) {
                update(result, 1LL * x * x * dp[k - 1][m - x] % MOD * dp[k][n] % MOD);
            }
        }
        printf("%d\n", result);
    }
}
