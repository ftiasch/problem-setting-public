#include "testlib.h"

#include <numeric>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    printf("%d %d\n", n, m);
    std::vector<int> label(n);
    std::iota(label.begin(), label.end(), 1);
    shuffle(label.begin(), label.end());
    for (int _ = 0; _ < m; ++ _) {
        int a = rnd.wnext(0, n - 1, w);
        int b = rnd.next(0, n - 1);
        if (rnd.next(0, 1)) {
            std::swap(a, b);
        }
        printf("%d %d\n", label[a], label[b]);
    }
}
