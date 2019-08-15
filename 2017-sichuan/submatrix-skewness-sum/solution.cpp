#include <cstdio>
#include <cstring>
#include <vector>

const int MOD = (int)1e9 + 7;

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
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d", &a.at(i).at(j));
            }
        }
        auto sum = a;
        for (int i = n - 1; i >= 0; -- i) {
            for (int j = n - 1; j >= 0; -- j) {
                update(sum.at(i).at(j), sum.at(i).at(j + 1));
            }
        }
        for (int i = n - 1; i >= 0; -- i) {
            for (int j = n - 1; j >= 0; -- j) {
                update(sum.at(i).at(j), sum.at(i + 1).at(j));
            }
        }
        int result = 0;
        for (int _ = 0; _ < 4; ++ _) {
            int tmp = 0;
            std::vector<int> csum(n + 1), msum(n + 1);
            for (int i = n; i >= 0; -- i) {
                int rsum = 0;
                for (int j = n; j >= 0; -- j) {
                    long long s = sum.at(i).at(j);
                    update(tmp, s * s % MOD * s % MOD * ((n - i) * (n - j)) % MOD);
                    update(tmp, MOD - 3 * s * s % MOD * rsum % MOD * (n - i) % MOD);
                    update(tmp, MOD - 3 * s * s % MOD * csum.at(j) % MOD * (n - j) % MOD);
                    update(tmp, 3 * s * s % MOD * msum.at(j) % MOD);
                    update(tmp, 6 * s * rsum % MOD * csum.at(j) % MOD);
                    update(msum.at(j), rsum);
                    update(rsum, sum.at(i).at(j));
                    update(csum.at(j), sum.at(i).at(j));
                }
            }
            if (_ & 1) {
                tmp = MOD - tmp;
            }
            update(result, tmp);
            auto rsum = sum;
            for (int i = 0; i <= n; ++ i) {
                for (int j = 0; j <= n; ++ j) {
                    rsum.at(i).at(j) = sum.at(n - j).at(i);
                }
            }
            sum.swap(rsum);
        }
        printf("%d\n", result);
    }
}
