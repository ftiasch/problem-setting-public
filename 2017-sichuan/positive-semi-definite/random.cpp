#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int m = std::atoi(argv[1]);
    for (int a = -m; a <= m; ++ a) {
        for (int b = -m; b <= m; ++ b) {
            for (int c = -m; c <= m; ++ c) {
                printf("%d %d %d\n", a, b, c);
            }
        }
    }
}
