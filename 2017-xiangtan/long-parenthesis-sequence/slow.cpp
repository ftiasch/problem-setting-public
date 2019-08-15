#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <vector>

template<typename T>
void update(T& x, T a)
{
    x = std::min(x, a);
}

const long long MAX = 1000000000000000000LL;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<long long> dp(1);
        for (int i = 0; i < n; ++ i) {
            int length, cost;
            char buffer[2];
            scanf("%d%s%d", &length, buffer, &cost);
            for (int _ = 0; _ < length; ++ _) {
                std::vector<long long> new_dp(dp.size() + 1, MAX);
                for (int j = 0; j < static_cast<int>(dp.size()); ++ j) {
                    if (dp.at(j) < MAX) {
                        if (*buffer == '(') {
                            update(new_dp.at(j + 1), dp.at(j));
                            if (j > 0) {
                                update(new_dp.at(j - 1), dp.at(j) + cost);
                            }
                        } else {
                            update(new_dp.at(j + 1), dp.at(j) + cost);
                            if (j > 0) {
                                update(new_dp.at(j - 1), dp.at(j));
                            }
                        }
                    }
                }
                dp.swap(new_dp);
            }
        }
        std::cout << dp.at(0) << std::endl;
    }
}
