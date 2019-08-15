#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int a = rnd.next(1, n);
    int b = rnd.next(1, n);
    printf("%d %d\n", a, b);
}
