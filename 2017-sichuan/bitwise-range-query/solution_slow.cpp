#include <algorithm>
#include <cstdio>
#include <cstdint>
#include <utility>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

int main()
{
    int n, m, a, b, q;
    while (scanf("%d%d%d%d%d", &n, &m, &a, &b, &q) == 5) {
        uint64_t flip = 0, add = 0, clear = 0;
        std::vector<std::pair<int, int>> lefts(q), rights(q);
        for (int i = 0; i < q; ++ i) {
            int weight;
            scanf("%d%d%d", &lefts.at(i).first, &rights.at(i).first, &weight);
            lefts.at(i).first --;
            rights.at(i).first --;
            lefts.at(i).second = rights.at(i).second = i;
            flip  |= static_cast<uint64_t>(weight) << i * 5;
            add   |= 1ULL << i * 5;
            clear |= 15ULL << i * 5;
        }
        std::sort(ALL(lefts));
        std::sort(ALL(rights));
        int left_index = 0;
        int right_index = 0;
        uint64_t sum = 0;
        std::vector<int> numbers(m, 1), result(q);
        for (int i = 0; i < n; ++ i) {
            auto& ref = numbers.at(i % m);
            ref = numbers.at((i + m - 1) % m) * a + ref * b & 15;
            while (left_index < q && lefts.at(left_index).first == i) {
                sum &= ~(31ULL << lefts.at(left_index).second * 5);
                left_index ++;
            }
            sum ^= flip;
            sum += ref * add;
            sum &= clear;
            while (right_index < q && rights.at(right_index).first == i) {
                auto&& j = rights.at(right_index).second;
                result.at(j) = sum >> j * 5 & 15;
                right_index ++;
            }
        }
        for (int i = 0; i < q; ++ i) {
            printf("%d\n", result.at(i));
        }
    }
}
