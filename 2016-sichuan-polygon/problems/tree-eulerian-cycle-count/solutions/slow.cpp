#include <cstdio>
#include <functional>
#include <map>
#include <utility>

const int MOD = (int)1e9 + 7;

int main()
{
    int n;
    scanf("%d", &n);
    std::map<std::pair<int, int>, int> tree;
    for (int i = 0; i < n - 1; ++ i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a --;
        b --;
        tree[{a, b}] += c << 1;
        tree[{b, a}] += c << 1;
    }
    std::function<int(int)> dfs = [&](int u) {
        if (!u) {
            bool empty = true;
            for (auto&& it : tree) {
                empty &= !it.second;
            }
            if (empty) {
                return 1;
            }
        }
        int result = 0;
        for (int v = 0; v < n; ++ v) {
            auto it = tree.find({u, v});
            if (it != tree.end() && it->second) {
                tree[{v, u}] --;
                int count = it->second --;
                result += (long long)dfs(v) * count % MOD;
                if (result >= MOD) {
                    result -= MOD;
                }
                tree[{u, v}] ++;
                tree[{v, u}] ++;
            }
        }
        return result;
    };
    printf("%d\n", dfs(0));
}
