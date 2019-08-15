#include <bits/stdc++.h>

bool check(int n, int msk, int sub)
{
    int tot = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            if ((msk >> tot & 1) && (~sub >> i & 1) && (~sub >> j & 1)) {
                return false;
            }
            tot ++;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::string s;
    while (std::cin >> n >> s) {
        int m = 0;
        for (size_t i = 0; i < s.size(); ++ i) {
            m = m * 2 + s[i] - '0';
        }
        int result = 0;
        for (int msk = 0; msk < 1 << n * (n - 1) / 2; ++ msk) {
            int sub = 0;
            while (!check(n, msk, sub)) {
                sub ++;
            }
            result += sub == m;
        }
        printf("%d\n", result);
    }
}
