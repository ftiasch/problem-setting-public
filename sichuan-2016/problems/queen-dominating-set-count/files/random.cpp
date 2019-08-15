#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int N = std::atoi(argv[1]);
    int K = std::atoi(argv[2]);
    int n = rnd.next(1, N);
    int m = rnd.next(1, N);
    int k = rnd.next(1, static_cast<int>(std::min(1LL * n * m, 1LL * K)));
    printf("%d %d %d\n", n, m, k);
}
