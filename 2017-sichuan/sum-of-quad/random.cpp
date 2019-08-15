#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    for (int _ = 0; _ < T; ++ _) {
        printf("%d\n", n);
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", rnd.next(0, 1000000000), " \n"[i == n - 1]);
        }
    }
}
