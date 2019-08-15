#include <cstdio>
#include <iostream>
#include <vector>

const int MOD = 2016;

std::vector<int> count(int n, int mod)
{
    std::vector<int> result(mod);
    for (int i = 1; i <= mod && i <= n; ++ i) {
        result.at(i % mod) = (n - i) / mod + 1;
    }
    return result;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a = count(n, MOD);
        std::vector<int> b = count(m, MOD);
        long long result = 0;
        for (int i = 0; i < MOD; ++ i) {
            for (int j = 0; j < MOD; ++ j) {
                if (i * j % MOD) {
                    continue;
                }
                result += static_cast<long long>(a.at(i)) * b.at(j);
            }
        }
        std::cout << result << std::endl;
    }
}
