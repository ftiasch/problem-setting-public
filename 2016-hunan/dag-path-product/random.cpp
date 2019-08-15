#include "testlib.h"

#include <algorithm>
#include <numeric>
#include <vector>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++ i) {
        int a = rnd.next(0, w);
        int b = rnd.next(0, w);
        printf("%d %d\n", a, b);
    }
    std::vector<int> label(n);
    std::iota(label.begin(), label.end(), 1);
    for (int i = 0; i < m; ++ i) {
        int a = 0;
        int b = 0;
        while (a == b) {
            a = rnd.next(0, n - 1);
            b = rnd.next(0, n - 1);
        }
        if (a > b) {
            std::swap(a, b);
        }
        printf("%d %d\n", label.at(a), label.at(b));
    }
}
