#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

int main()
{
    int n, max;
    while (scanf("%d%d", &n, &max) == 2) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        auto values = a;
        std::sort(ALL(values));
        values.erase(std::unique(ALL(values)), values.end());
        for (int i = 0; i < n; ++ i) {
            a.at(i) = std::lower_bound(ALL(values), a.at(i)) - values.begin();
        }
        int m = values.size();
        int free = max;
        for (auto&& v : values) {
            free -= 1 <= v && v <= max;
        }
        auto cnt = [&](int i) -> int{
            if (i == m) {
                return free;
            }
            return 1 <= values.at(i) && values.at(i) <= max;
        };
        std::vector<std::vector<int>> nxt(n + 1, std::vector<int>(m + 1));
        nxt.at(n).assign(m + 1, n);
        for (int i = n - 1; i >= 0; -- i) {
            nxt.at(i) = nxt.at(i + 1);
            nxt.at(i).at(a.at(i)) = i;
        }
        std::vector<long long> result(4);
        for (int x = 0; x <= m; ++ x) {
            for (int y = 0; y <= m; ++ y) {
                for (int z = 0; z <= m; ++ z) {
                    long long way = (long long)cnt(x) * cnt(y) * cnt(z);
                    int aa[] = {x, y, z};
                    int lcs = 0;
                    for (int mask = 1; mask < 8; ++ mask) {
                        int pos = -1;
                        for (int i = 0; i < 3 && pos < n; ++ i) {
                            if (mask >> i & 1) {
                                pos = nxt.at(pos + 1).at(aa[i]);
                            }
                        }
                        if (pos < n) {
                            lcs = std::max(lcs, __builtin_popcount(mask));
                        }
                    }
                    result.at(lcs) += way;
                }
            }
        }
        for (int i = 0; i < 4; ++ i) {
            std::cout << result.at(i) << " \n"[i == 3];
        }
    }
}
