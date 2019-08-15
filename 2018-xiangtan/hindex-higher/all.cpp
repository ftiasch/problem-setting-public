#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j <= i; ++ j) {
            printf("%d %d\n", i, j);
        }
    }
}
