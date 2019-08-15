#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++ i) {
        int a = rnd.next(1, m);
        int b = rnd.next(1, m);
        printf("%d %d\n", a, b);
    }
    return 0;
}
