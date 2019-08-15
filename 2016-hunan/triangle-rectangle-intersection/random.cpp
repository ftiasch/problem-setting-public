#include "testlib.h"

#include <algorithm>
#include <numeric>
#include <vector>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    while (T --) {
        int a[8];
        for (int i = 0; i < 8; i += 2) {
            while (true) {
                a[i] = rnd.next(0, m);
                a[i | 1] = rnd.next(0, m);
                if (a[i] != a[i | 1]) {
                    break;
                }
            }
            if (i >= 4 && a[i] > a[i | 1]) {
                std::swap(a[i], a[i | 1]);
            }
        }
        printf("%d %d %d %d\n%d %d %d %d\n", a[0], a[2], a[1], a[3], a[4], a[6], a[5], a[7]);
    }
}
