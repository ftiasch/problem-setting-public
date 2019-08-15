#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int count = std::atoi(argv[1]);
    while (count --) {
        int n = rnd.next(1, std::atoi(argv[2]));
        printf("%d %d\n", n, rnd.next(0, n));
    }
}
