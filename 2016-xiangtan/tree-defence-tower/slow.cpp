#include <algorithm>
#include <cstdio>
#include <climits>
#include <functional>
#include <numeric>
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
        int result = INT_MAX;
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        do {
            std::vector<bool> alive(n, true);
            int cost = 0;
            for (int i = 0; i < n; ++ i) {
                int u = p[i];
                for (int v : tree.at(u)) {
                    if (alive.at(v)) {
                        cost += a[v];
                    }
                }
                alive[u] = false;
            }
            result = std::min(result, cost);
        } while (std::next_permutation(p.begin(), p.end()));
        printf("%d\n", result);
    }
}
