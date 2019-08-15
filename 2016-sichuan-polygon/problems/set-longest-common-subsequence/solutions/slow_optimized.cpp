#include <algorithm>
#include <cstdio>
#include <vector>

void update(int &x, int a)
{
    x = std::max(x, a);
}

int main()
{
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
        a[i] --;
    }
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    for (int i = 0; i < m; ++ i) {
        std::vector<int> count(l);
        int s;
        scanf("%d", &s);
        for (int _ = 0; _ < s; ++ _) {
            int b;
            scanf("%d", &b);
            count.at(b - 1) ++;
        }
        for (int j = 0; j <= n; ++ j) {
            int total = 0;
            std::vector<int> tmp_count(l);
            update(dp[i + 1][j], dp[i][j]);
            for (int k = j; k < n && total < s; ++ k) {
                if (tmp_count[a[k]] < count[a[k]]) {
                    total ++;
                    tmp_count[a[k]] ++;
                }
                update(dp[i + 1][k + 1], dp[i][j] + total);
            }
        }
    }
    printf("%d\n", *std::max_element(dp[m].begin(), dp[m].end()));
}
