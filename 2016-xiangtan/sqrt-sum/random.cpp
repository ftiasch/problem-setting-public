#include "testlib.h"

std::vector<int> gen_ints(int n, int m, int w)
{
    std::vector<int> a(n);
    a[0] = 1;
    a[1] = rnd.next(0, m - 1);
    for (int i = a[0] + a[1]; i < m; ++ i) {
        a.at(rnd.wnext(2, n - 1, w)) ++;
    }
    shuffle(a.begin(), a.end());
    return a;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int w1 = std::atoi(argv[3]);
    int w2 = std::atoi(argv[3]);
    auto a = gen_ints(n, m, w1);
    auto b = gen_ints(n, m, w2);
    printf("%d %d\n", (int)a.size(), (int)b.size());
    for (int i = 0; i < (int)a.size(); ++ i) {
        printf("%d%c", a.at(i), " \n"[i == (int)a.size() - 1]);
    }
    for (int i = 0; i < (int)b.size(); ++ i) {
        printf("%d%c", b.at(i), " \n"[i == (int)b.size() - 1]);
    }
    return 0;
}
