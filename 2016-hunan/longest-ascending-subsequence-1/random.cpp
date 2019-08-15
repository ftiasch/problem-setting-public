#include "testlib.h"

#include <algorithm>
#include <numeric>
#include <vector>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    printf("%d\n", n);
    int total = 0;
    int index = rnd.next(0, n - 1);
    int value = rnd.next(0, n - 1);
    if (total == value) {
        total ++;
    }
    for (int i = 0; i < n; ++ i) {
        int elem = value;
        if (i != index) {
            elem = total ++;
            if (total == value) {
                total ++;
            }
        }
        if (rnd.wnext(0, 1, m)) {
            elem = -1;
        }
        printf("%d%c", elem + 1, " \n"[i == n - 1]);
    }
}
