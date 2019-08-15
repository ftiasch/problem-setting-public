#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    for (int _ = 0; _ < T; ++ _) {
        int a = rnd.next(1, m);
        int b = rnd.next(1, m);
        printf("%d %d\n", a, b);
    }
}
