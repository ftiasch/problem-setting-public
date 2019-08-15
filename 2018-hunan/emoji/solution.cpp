#include <bits/stdc++.h>

using Map = std::vector<std::vector<char>>;

int solve(Map& g, int n, int m, char up, char down)
{
    char ch[] = {up, down};
    int result = 0;
    for (int j = 0; j < m; ++ j) {
        for (int i = 0; i < n; ++ i) {
            if (g[i][j] == up || g[i][j] == down) {
                int x = i;
                int y = j;
                int t = g[i][j] == up ? 0 : 1;
                int len = 0;
                while (0 <= x && 0 <= y && x < n && y < m && g[x][y] == ch[t]) {
                    g[x][y] = '@';
                    y ++;
                    if (t) {
                        x --;
                    } else {
                        x ++;
                    }
                    t ^= 1;
                    len ++;
                }
                result += len / 3;
            }
        }
    }
    return result;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        Map g(n, std::vector<char>(m + 1)), g2(m, std::vector<char>(n + 1));
        for (int i = 0; i < n; ++ i) {
            scanf("%s", g[i].data());
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                g2[j][i] = g[i][j];
            }
        }
        printf("%d\n", solve(g, n, m, '^', 'v') + solve(g2, m, n, '<', '>'));
    }
}
