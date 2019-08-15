#include <cstdio>
#include <cstring>

const int N = 20;
const int M = 500;
const int MOD = (int)1e9 + 7;

int a[N], b[M], dp[N + 1][M + 2][M + 2];

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
        }
        for (int i = 0; i < m; ++ i) {
            scanf("%d", b + i);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0][m + 1] = 1;
        for (int j = 0; j < m; ++ j) {
            for (int i = n - 1; i >= 0; -- i) {
                for (int mi = 0; mi <= m; ++ mi) {
                    for (int ma = mi + 1; ma <= m + 1; ++ ma) {
                        if (mi < b[j] && b[j] < ma) {
                            if (a[i] == 0) {
                                update(dp[i + 1][b[j]][ma], dp[i][mi][ma]);
                            } else {
                                update(dp[i + 1][mi][b[j]], dp[i][mi][ma]);
                            }
                        }
                    }
                }
            }
        }
        int result = 0;
        for (int mi = 0; mi <= m; ++ mi) {
            for (int ma = mi + 1; ma <= m + 1; ++ ma) {
                update(result, dp[n][mi][ma]);
            }
        }
        printf("%d\n", result);
    }
}
