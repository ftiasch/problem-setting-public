#include <bits/stdc++.h>

int main()
{
    for (int h = 1; h <= 50; ++ h) {
        std::vector<std::vector<bool>> dp(1, {true});
        for (int c = 1; c <= h * 10; ++ c) {
            dp.emplace_back(dp[c - 1]);
            dp.back().push_back(false);
            int maxd = (c / h) * h;
            int result = 0;
            for (int x = 1; x <= c; ++ x) {
                dp[c][x] = maxd ? dp[c - 1][x - 1] : false;
                if (dp[c][x]) {
                    result ++;
                }
            }
            assert(result == std::max(c - h + 1, 0));
        }
    }
}
