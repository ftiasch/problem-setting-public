#include <algorithm>
#include <cstdio>
#include <vector>

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        int result[] = {0, 0, 0, 0};
        for (int x = 1; x <= m; ++ x) {
            for (int y = 1; y <= m; ++ y) {
                for (int z = 1; z <= m; ++ z) {
                    int b[] = {x, y, z};
                    std::vector<int> dp[4];
                    dp[0].resize(n + 1);
                    for (int i = 1; i <= 3; ++ i) {
                        dp[i].resize(n + 1);
                        for (int j = 1; j <= n; ++ j) {
                            if (a[j - 1] == b[i - 1]) {
                                dp[i][j] = dp[i - 1][j - 1] + 1;
                            } else {
                                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                            }
                        }
                    }
                    result[*std::max_element(dp[3].begin(), dp[3].end())] ++;
                }
            }
        }
        printf("%d %d %d %d\n", result[0], result[1], result[2], result[3]);
    }
}
