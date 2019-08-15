                                                \
#include <cstdio>
#include <vector>

const int MOD = 1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<char> buffer(n + 1);
        scanf("%s", buffer.data());
        std::vector<int> power(n + 1);
        power.at(0) = 1;
        for (int i = 1; i <= n; ++ i) {
            power.at(i) = power.at(i - 1) * 10LL % MOD;
        }
        int result = 0;
        for (int i = 0, suffix = 0; i < n; ++ i) {
            update(suffix, (long long)power.at(i) * (buffer.at(n - 1 - i) - '0') % MOD);
            update(result, (long long)suffix * (n - 1LL - i) % MOD);
        }
        std::vector<int> suffix(n + 1);
        for (int i = n - 1; i >= 0; -- i) {
            suffix.at(i) = (suffix.at(i + 1) * 10LL + buffer.at(i) - '0') % MOD;
        }
        std::vector<int> sum(n + 1);
        for (int i = n - 1; i >= 0; -- i) {
            sum.at(i) = (sum.at(i + 1) + suffix.at(i)) % MOD;
        }
        for (int i = 1; i <= n; ++ i) {
            update(result, (long long)(sum.at(0) + MOD - sum.at(i)) * power.at(n - i) % MOD);
        }
        for (int i = 0; i < n; ++ i) {
            update(result, MOD - (long long)power.at(n - i) * sum.at(i + 1) % MOD);
        }
        for (int i = 0, prefix = 0; i < n; ++ i) {
            prefix = ((long long)prefix * 10LL + buffer.at(i) - '0') % MOD;
            update(result, (long long)prefix * power.at(n - 1 - i) % MOD * (n - 1LL - i) % MOD);
        }
        printf("%d\n", result);
    }
}
