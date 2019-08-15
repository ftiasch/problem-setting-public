#include "testlib.h"

#include <algorithm>
#include <cstdio>
#include <numeric>

const int MOD = (int)1e9 + 7;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    std::vector<int> ns;
    for (int i = 1; i + 1 < argc; i += 2) {
        auto c = std::atoi(argv[i]);
        auto n = std::atoi(argv[i + 1]);
        while (c --) {
            ns.push_back(n);
        }
    }
    for (auto&& n : ns) {
        printf("%d\n", n);
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 1);
        shuffle(p.begin(), p.end());
        std::vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 0);
        int l = rnd.next(1, n);
        indices.resize(l);
        std::vector<int> values;
        for (int i = 0; i < l; ++ i) {
            values.push_back(p.at(indices.at(i)));
        }
        std::sort(values.begin(), values.end());
        for (int i = 0; i < l; ++ i) {
            p.at(indices.at(i)) = values.at(i);
        }
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", p.at(i), " \n"[i == n - 1]);
        }
    }
}
