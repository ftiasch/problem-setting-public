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
    std::vector<int> ways(1 << n + 1);
    for (int _ = 0; _ < m; ++ _) {
        int c, k;
        scanf("%d%d", &c, &k);
        int mask = 0;
        while (k --) {
            int x;
            scanf("%d", &x);
            mask |= 1 << x;
        }
        ways.at(mask) += c;
    }
    for (int i = 1; i <= n; ++ i) {
        std::vector<int> new_ways(1 << n + 1);
        for (int mask = 0; mask < 1 << n + 1; ++ mask) {
            new_ways.at(mask & ~(1 << i)) += ways.at(mask);
            new_ways.at((mask | 1 << i) ^ (mask >> i & 1)) += ways.at(mask);
        }
        ways = new_ways;
    }
    int result = 0;
    for (int mask = 0; mask < 1 << n; ++ mask) {
        result += sqr(ways.at(mask << 1 | 1));
        if (result >= MOD) {
            result -= MOD;
        }
    }
    printf("%d\n", result);
}
