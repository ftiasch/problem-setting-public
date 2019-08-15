#include <cstdio>
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
    std::vector<int> degree(n), count(n - 1);
    int m = 0;
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        scanf("%d%d%d", &a, &b, &count.at(i));
        a --;
        b --;
        auto&& c = count.at(i) << 1;
        degree.at(a) += c;
        degree.at(b) += c;
        m += c;
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
    int result = 1;
    for (int i = 0; i < n; ++ i) {
        int d = degree.at(i) >> 1;
        if (i) {
            d --;
        }
        result = (long long)result * factorial.at(d) % MOD;
    }
    for (int i = 0; i < n - 1; ++ i) {
        auto&& c = count.at(i);
        result = (long long)result * c % MOD * binom(2 * c, c) % MOD;
    }
    printf("%d\n", result);
}
