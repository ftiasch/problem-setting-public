#include <algorithm>
#include <cstdio>
#include <vector>

const int MOD = 1e9 + 7;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<char> buffer(n + 1);
        scanf("%s", buffer.data());
        int result = 0;
        for (int l = 0; l < n; ++ l) {
            for (int r = l + 1; r <= n; ++ r) {
                std::reverse(buffer.begin() + l, buffer.begin() + r);
                int remainder = 0;
                for (int i = 0; i < n; ++ i) {
                    remainder = (remainder * 10LL + buffer.at(i) - '0') % MOD;
                }
                result += remainder;
                if (result >= MOD) {
                    result -= MOD;
                }
                std::reverse(buffer.begin() + l, buffer.begin() + r);
            }
        }
        printf("%d\n", result);
    }
}
