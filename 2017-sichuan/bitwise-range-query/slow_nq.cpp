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
        std::vector<int> weight(q);
        std::vector<std::pair<int, int>> lefts(q), rights(q);
        for (int i = 0; i < q; ++ i) {
            scanf("%d%d%d", &lefts.at(i).first, &rights.at(i).first, &weight.at(i));
            lefts.at(i).first --;
            rights.at(i).first --;
            lefts.at(i).second = rights.at(i).second = i;
        }
        std::sort(ALL(lefts));
        std::sort(ALL(rights));
        int left_index = 0;
        int right_index = 0;
        std::vector<int> numbers(m, 1), sum(q), result(q);
        for (int i = 0; i < n; ++ i) {
            auto& ref = numbers.at(i % m);
            ref = numbers.at((i + m - 1) % m) * a + ref * b & 15;
            while (left_index < q && lefts.at(left_index).first == i) {
                sum.at(lefts.at(left_index).second) = 0;
                left_index ++;
            }
            for (int j = 0; j < q; ++ j) {
                sum.at(j) = (sum.at(j) ^ weight.at(j)) + ref & 15;
            }
            while (right_index < q && rights.at(right_index).first == i) {
                auto&& j = rights.at(right_index).second;
                result.at(j) = sum.at(j);
                right_index ++;
            }
        }
        for (int i = 0; i < q; ++ i) {
            printf("%d\n", result.at(i));
        }
    }
}
