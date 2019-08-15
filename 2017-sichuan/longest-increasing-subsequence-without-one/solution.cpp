#include <algorithm>
#include <cassert>
#include <cstdio>
#include <climits>
#include <vector>

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        std::vector<int> ori_f(n, 1);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < i; ++ j) {
                if (a.at(j) < a.at(i)) {
                    ori_f.at(i) = std::max(ori_f.at(i), ori_f.at(j) + 1);
                }
            }
        }
        std::vector<int> g(n + 1);
        for (int ban = 0; ban < n; ++ ban) {
            int sum2 = 0;
            g.assign(n + 1, INT_MAX);
            g.at(0) = INT_MIN;
            for (int i = 0; i < n; ++ i) {
                if (i == ban) {
                    continue;
                }
                int f = ori_f.at(i);
                if (g.at(f - 1) >= a.at(i)) {
                    f --;
                }
                assert(g.at(f - 1) <= a.at(i));
                g.at(f) = std::min(g.at(f), a.at(i));
                sum2 ^= f * f;
            }
            printf("%d%c", sum2, " \n"[ban == n - 1]);
        }
    }
}
