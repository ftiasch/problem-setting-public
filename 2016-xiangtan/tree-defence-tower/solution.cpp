#include <cstdio>
#include <functional>
#include <vector>

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        std::vector<std::vector<int>> tree(n);
        for (int i = 0; i < n - 1; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            tree.at(a).push_back(b);
            tree.at(b).push_back(a);
        }
        std::function<int(int, int)> dfs = [&](int p, int u) -> int {
            int result = 0;
            if (~p) {
                result += std::min(a.at(p), a.at(u));
            }
            for (int v : tree.at(u)) {
                if (v != p) {
                    result += dfs(u, v);
                }
            }
            return result;
        };
        printf("%d\n", dfs(-1, 0));
    }
}
