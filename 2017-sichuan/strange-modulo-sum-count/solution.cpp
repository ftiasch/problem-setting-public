#include <cstdio>

const int MOD = (int)1e9 + 7;
const long long BND = (long long)1e10 + 19;

int inv(int a)
{
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inv(MOD % a) % MOD;
}

int main()
{
    int INV_BND = inv(BND % MOD);
    int n;
    while (scanf("%d", &n) == 1) {
        int result = 1;
        int product = 1;
        for (int i = 0; i < n; ++ i) {
            int a;
            scanf("%d", &a);
            int inv_a = MOD - a;
            result = (long long)result * (BND % MOD + inv_a) % MOD;
            product = (long long)product * inv_a % MOD;
        }
        printf("%d\n", (long long)(result + MOD - product) * INV_BND % MOD);
    }
}
