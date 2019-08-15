#include "testlib.h"

std::string generate(int n, int w)
{
    if (n == 1) {
        return "()";
    }
    if (rnd.wnext(0, 1, w)) {
        int a = rnd.next(1, n - 1);
        int b = n - a;
        auto s = generate(a, w);
        return s + generate(b, w);
    }
    return std::string("(") + generate(n - 1, w) + ")";
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]) >> 1;
    int m = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    printf("%d %d\n%s\n", n * 2, m, generate(n, w).c_str());
    for (int _ = 0; _ < m; ++ _) {
        int a = 0, b = 0;
        while (a == b) {
            a = rnd.next(1, n);
            b = rnd.next(1, n);
        }
        printf("%d %d\n", a, b);
    }
}
