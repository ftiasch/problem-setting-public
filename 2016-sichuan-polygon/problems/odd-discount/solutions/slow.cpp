#include <cstdio>
#include <vector>

const int MOD = (int)1e9 + 7;

int sqr(int x)
{
    return 1LL * x * x % MOD;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::pair<int, int>> groupons;
    for (int _ = 0; _ < m; ++ _) {
        int c, k;
        scanf("%d%d", &c, &k);
        int mask = 0;
        while (k --) {
            int x;
            scanf("%d", &x);
            mask |= 1 << x - 1;
        }
        groupons.emplace_back(mask, c);
    }
    int result = 0;
    for (int mask = 0; mask < 1 << n; ++ mask) {
        int sum = 0;
        for (auto&& groupon : groupons) {
            if (__builtin_parity(groupon.first & mask)) {
                sum += groupon.second;
            }
        }
        (result += sqr(sum)) %= MOD;
    }
    printf("%d\n", result);
}
