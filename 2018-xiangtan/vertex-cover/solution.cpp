#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int MOD = 1000000007;

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::string s;
    while (std::cin >> n >> s) {
        std::reverse(s.begin(), s.end());
        int result = 1, pow_in = 1, pow_out = 1;
        for (int i = n - 1; i >= 0; -- i) {
            bool in = !(i < static_cast<int>(s.size()) && s[i] == '1');
            if (in) {
                result = 1LL * result * pow_out % MOD;
                (pow_in *= 2) %= MOD;
            } else {
                result = 1LL * result * (pow_in - 1) % MOD * pow_out % MOD;
                (pow_out *= 2) %= MOD;
            }
        }
        printf("%d\n", result);
    }
}
