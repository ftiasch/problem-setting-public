#include "testlib.h"

#include <algorithm>
#include <cstdio>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    std::vector<std::pair<int, int>> params;
    int w = std::atoi(argv[1]);
    for (int i = 2; i + 2 < argc; i += 3) {
        auto c = std::atoi(argv[i]);
        auto n = std::atoi(argv[i + 1]);
        auto m = std::atoi(argv[i + 2]);
        while (c --) {
            params.emplace_back(n, m);
        }
    }
    for (auto&& param : params) {
        int n = param.first;
        int m = param.second;
        std::vector<int> partition;
        for (int i = 0; i < n - 1; ++ i) {
            partition.push_back(rnd.next(1, m - n + 1));
        }
        std::sort(partition.begin(), partition.end());
        for (int i = 0; i < n - 1; ++ i) {
            partition.at(i) += i;
        }
        partition.push_back(m);
        printf("%d\n", n);
        for (int i = 0; i < n; ++ i) {
            int length = partition.at(i);
            if (i > 0) {
                length -= partition.at(i - 1);
            }
            char ch = "()"[rnd.next(0, 1)];
            printf("%d %c %d\n", length, ch, rnd.next(1, w));
        }
    }
}
