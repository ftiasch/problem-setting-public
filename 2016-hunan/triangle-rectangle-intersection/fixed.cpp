#include "testlib.h"

#include <algorithm>
#include <numeric>
#include <vector>

void generate(int* a, int m, int i)
{
    if (i < 8) {
        for (a[i] = 0; a[i] <= m; ++ a[i]) {
            if ((i & 1) && a[i] == a[i ^ 1]) {
                continue;
            }
            if (i >= 4 && (i & 1) && a[i ^ 1] > a[i]) {
                continue;
            }
            generate(a, m, i + 1);
        }
    } else {
        printf("%d %d %d %d\n%d %d %d %d\n", a[0], a[2], a[1], a[3], a[4], a[6], a[5], a[7]);
    }
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int m = std::atoi(argv[1]);
    int a[8];
    generate(a, m, 0);
}
