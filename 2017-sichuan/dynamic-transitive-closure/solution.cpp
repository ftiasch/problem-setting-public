#include <cstdio>
#include <iostream>
#include <vector>

const int MOD = (int)1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int n, m, q;
    while (scanf("%d%d%d", &n, &m, &q) == 3) {
        std::vector<std::vector<int>> graph(n, std::vector<int>(n));
        for (int i = 0; i < m; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            graph.at(a).at(b) ++;
        }
        std::vector<std::vector<int>> ways(n, std::vector<int>(n));
        for (int s = 0; s < n; ++ s) {
            auto& w = ways.at(s);
            w.at(s) = 1;
            for (int u = s; u < n; ++ u) {
                for (int v = u + 1; v < n; ++ v) {
                    if (graph.at(u).at(v)) {
                        update(w.at(v), w.at(u));
                    }
                }
            }
        }
        std::vector<int> color(n, 1);
        while (q --) {
            int v;
            scanf("%d", &v);
            v --;
            color.at(v) ^= 1;
            if (color.at(v)) {
                for (int x = 0; x < v; ++ x) {
                    for (int y = v + 1; y < n; ++ y) {
                        update(ways.at(x).at(y), (long long)ways.at(x).at(v) * ways.at(v).at(y) % MOD);
                    }
                }
            } else {
                for (int x = 0; x < v; ++ x) {
                    for (int y = v + 1; y < n; ++ y) {
                        update(ways.at(x).at(y), MOD - (long long)ways.at(x).at(v) * ways.at(v).at(y) % MOD);
                    }
                }
            }
            int result = 0;
            for (int i = 0; i < n; ++ i) {
                for (int j = i + 1; j < n; ++ j) {
                    if (color.at(i) && color.at(j) && ways.at(i).at(j)) {
                        result ++;
                    }
                }
            }
            printf("%d\n", result);
        }
    }
}
