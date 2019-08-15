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
        for (int j = 0; j < m; ++ j) {
            putchar('0' + rnd.wnext(0, 1, -w));
        }
        puts("");
    }
}
