#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

const int MOD = (int)1e9 + 7;

int inverse(int a)
{
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

void update(int &x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int binom(const std::vector<int>& factorial, int n, int k)
{
    return (long long)factorial.at(n) * inverse((long long)factorial.at(k) * factorial.at(n - k) % MOD) % MOD;
}

int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3) {
        int m = std::max(std::max(a, b), c);
        std::vector<int> factorial(m + 1);
        factorial[0] = 1;
        for (int i = 1; i <= m; ++ i) {
            factorial[i] = (long long)i * factorial[i - 1] % MOD;
        }
        int result = 0;
        if ((a & 1) == (b & 1) && (b & 1) == (c & 1)) {
            for (int i = 0; i <= a; ++ i) {
                int j = i - (a - b) / 2;
                int k = j - (b - c) / 2;
                if (0 <= j && j <= b && 0 <= k && k <= c) {
                    int ways = 0;
                    update(ways, (long long)(a - i) * j % MOD);
                    update(ways, (long long)(a - i) * (c - k) % MOD);
                    update(ways, (long long)j * k % MOD);
                    update(result, (long long)ways * binom(factorial, a, i) % MOD * binom(factorial, b, j) % MOD * binom(factorial, c, k) % MOD * factorial.at(i + b - j) % MOD * factorial.at(a - i + k - 1) % MOD * factorial.at(j + c - k - 1) % MOD);
                }
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
