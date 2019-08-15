#include <cstdio>
#include <vector>

const int MOD = (int)1e9 + 7;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        int result = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                for (int k = j + 1; k < n; ++ k) {
                    for (int l = k + 1; l < n; ++ l) {
                        result += (long long)a[i] * a[j] % MOD * a[k] % MOD * a[l] % MOD;
                        if (result >= MOD) {
                            result -= MOD;
                        }
                    }
                }
            }
        }
        printf("%d\n", result);
    }
}
