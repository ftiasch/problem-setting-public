#include <cstdio>
#include <functional>
#include <utility>
#include <vector>

const int MOD = (int)1e9 + 7;

int inverse(int a)
{
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int main()
{
    int n;
    scanf("%d", &n);
    std::vector<std::vector<std::pair<int, int>>> tree(n);
    int m = 0;
    for (int i = 0; i < n - 1; ++ i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a --;
        b --;
        m += c << 1;
        tree.at(a).emplace_back(b, c);
        tree.at(b).emplace_back(a, c);
    }
    std::vector<int> factorial(m + 1);
    factorial[0] = 1;
    for (int i = 1; i <= m; ++ i) {
        factorial[i] = (long long)factorial[i - 1] * i % MOD;
    }
    auto&& binom = [&](int n, int m) -> long long {
        if (n < m) {
            return 0;
        }
        return (long long)factorial.at(n) * inverse(factorial.at(m)) % MOD * inverse(factorial.at(n - m)) % MOD;
    };
    std::function<std::pair<int, int>(int, int)> dfs = [&](int p, int u) -> std::pair<int, int> {
        int degree = 0;
        int ways = 1;
        for (auto&& it : tree.at(u)) {
            auto&& v = it.first;
            auto&& c = it.second;
            if (v != p) {
                degree += c;
                auto&& subtree = dfs(u, v);
                ways = (long long)ways * factorial.at(c << 1) % MOD * inverse(factorial.at(c)) % MOD * binom(subtree.first + c - 1, c - 1) % MOD * subtree.second % MOD;
            }
        }
        ways = (long long)ways * factorial.at(degree) % MOD;
        return {degree, ways};
    };
    printf("%d\n", dfs(-1, 0).second);
}
