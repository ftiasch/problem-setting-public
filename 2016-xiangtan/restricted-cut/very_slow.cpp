#include <cstdio>
#include <climits>
#include <functional>
#include <vector>

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(m), b(m), c(m);
        std::vector<std::vector<int>> graph(n, std::vector<int>(n));
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d%d", &a.at(i), &b.at(i), &c.at(i));
            a.at(i) --;
            b.at(i) --;
            graph.at(a.at(i)).at(b.at(i)) += c.at(i);
        }
        int result = INT_MAX;
        std::vector<int> cuts[2];
        cuts[0].push_back(0);
        cuts[1].push_back(n - 1);
        std::function<void(int, int)> dfs = [&](int u, int sum)
        {
            if (sum >= result) {
                return;
            }
            int left = n - 1 - u;
            if ((int)cuts[0].size() + left < 3 || (int)cuts[1].size() + left < 3) {
                return;
            }
            if (left) {
                for (int i = 0; i < 2; ++ i) {
                    cuts[i].push_back(u);
                    int tmp = sum;
                    if (i) {
                        for (int v : cuts[0]) {
                            sum += graph.at(v).at(u);
                        }
                    } else {
                        for (int v : cuts[1]) {
                            sum += graph.at(u).at(v);
                        }
                    }
                    dfs(u + 1, sum);
                    sum = tmp;
                    cuts[i].pop_back();
                }
            } else {
                result = sum;
            }
        };
        dfs(1, graph.at(0).at(n - 1));
        printf("%d\n", result);
    }
}
