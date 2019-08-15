#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdint>
#include <utility>
#include <vector>

const int M = 100000;
const int Q = 13;

int numbers[M];
uint16_t weight[Q], sum[Q], result[Q];

int main()
{
    int n, m, a, b, q;
    while (scanf("%d%d%d%d%d", &n, &m, &a, &b, &q) == 5) {
        assert(m < M);
        std::vector<std::pair<int, int>> events;
        events.emplace_back(0, -1);
        for (int i = 0; i < q; ++ i) {
            int l, r, w;
            scanf("%d%d%d", &l, &r, &w);
            weight[i] = w;
            events.emplace_back(l - 1, i);
            events.emplace_back(r, q + i);
        }
        std::sort(events.begin(), events.end());
        std::fill(numbers, numbers + m, 1);
        int j_mod_m = 0;
        int prev_j_mod_m = m - 1;
        for (int i = 1; i < static_cast<int>(events.size()); ++ i) {
            for (int j = events.at(i - 1).first; j < events.at(i).first; ++ j) {
                auto& ref = numbers[j_mod_m];
                ref = numbers[prev_j_mod_m] * a + ref * b & 15;
                for (int k = 0; k < Q; ++ k) {
                    sum[k] = (sum[k] ^ weight[k]) + ref & 15;
                }
                prev_j_mod_m = j_mod_m;
                j_mod_m ++;
                if (j_mod_m == m) {
                    j_mod_m = 0;
                }
            }
            auto&& j = events.at(i).second;
            if (j < q) {
                sum[j] = 0;
            } else {
                j -= q;
                result[j] = sum[j];
            }
        }
        for (int i = 0; i < q; ++ i) {
            printf("%d\n", result[i]);
        }
    }
}
