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

int pow(int x)
{
    return (long long)x * x % MOD * x % MOD;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d", &a.at(i).at(j));
            }
        }
        std::vector<std::vector<int>> sum(n + 1, std::vector<int>(n + 1));
        for (int i = n - 1; i >= 0; -- i) {
            for (int j = n - 1; j >= 0; -- j) {
                sum.at(i).at(j) = a.at(i).at(j);
                update(sum.at(i).at(j), sum.at(i + 1).at(j));
                update(sum.at(i).at(j), sum.at(i).at(j + 1));
                update(sum.at(i).at(j), MOD - sum.at(i + 1).at(j + 1));
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++ i) {
            for (int ii = i + 1; ii <= n; ++ ii) {
                for (int j = 0; j < n; ++ j) {
                    for (int jj = j + 1; jj <= n; ++ jj) {
                        int s = sum.at(i).at(j);
                        update(s, MOD - sum.at(ii).at(j));
                        update(s, MOD - sum.at(i).at(jj));
                        update(s, sum.at(ii).at(jj));
                        update(result, pow(s));
                    }
                }
            }
        }
        printf("%d\n", result);
    }
}
