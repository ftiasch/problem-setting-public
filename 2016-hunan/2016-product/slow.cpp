#include <cstdio>
#include <iostream>

const int MOD = 2016;

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        long long result = 0;
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= m; ++ j) {
                if (i * j % MOD == 0) {
                    result ++;
                }
            }
        }
        std::cout << result << std::endl;
    }
}
