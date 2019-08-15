#include <cstdio>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

const int N = 100000;

int color[N], a[N], b[N], count[N];
std::vector<int> tree[N];

void dfs(int p, int u, int c)
{
    count[color[u]] |= c;
    for (auto&& v : tree[u]) {
        if (v != p) {
            dfs(u, v, c);
        }
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", color + i);
            color[i] --;
            tree[i].clear();
        }
        for (int i = 0; i < n - 1; ++ i) {
            scanf("%d%d", a + i, b + i);
            a[i] --;
            b[i] --;
            tree[a[i]].push_back(b[i]);
            tree[b[i]].push_back(a[i]);
        }
        for (int i = 0; i < n - 1; ++ i) {
            memset(count, 0, sizeof(*count) * n);
            dfs(a[i], b[i], 1);
            dfs(b[i], a[i], 2);
            int result = 0;
            for (int i = 0; i < n; ++ i) {
                result += count[i] == 3;
            }
            printf("%d\n", result);
        }
    }
}
