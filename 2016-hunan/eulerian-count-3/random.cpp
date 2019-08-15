#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int p = rnd.next(0, 1);
    auto random = [&]() {
        return rnd.next(1, n + p >> 1) * 2 - p;
    };
    printf("%d ", random());
    printf("%d ", random());
    printf("%d\n", random());
    return 0;
}
