#include <cstdio>
#include <vector>

const int MOD = (int)1e9 + 7;

int inverse(int a)
{
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int binom(int n, int k, int result)
{
    for (int i = 0; i < k; ++ i) {
        result = (long long)result * (n - i) % MOD;
    }
    return result;
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int inv_fact_k = 1;
    for (int i = 1; i <= k; ++ i) {
        inv_fact_k = (long long)inv_fact_k * i % MOD;
    }
    inv_fact_k = inverse(inv_fact_k);
    int result = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            int count = 0;
            for (int x = 0; x < n; ++ x) {
                for (int y = 0; y < m; ++ y) {
                    if (x == i || y == j || x + y == i + j || x - y == i - j) {
                        count ++;
                    }
                }
            }
            (result += binom(n * m, k, inv_fact_k)) %= MOD;
            (result += MOD - binom(n * m - count, k, inv_fact_k)) %= MOD;
        }
    }
    printf("%d\n", result);
    return 0;
}
