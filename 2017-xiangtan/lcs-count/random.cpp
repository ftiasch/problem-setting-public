#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    int m = std::atoi(argv[3]);
    for (int _ = 0; _ < T; ++ _) {
        printf("%d %d\n", n, rnd.next(1, m));
        int k = rnd.next(1, n);
        std::vector<int> values;
        for (int i = 0; i < k; ++ i) {
            values.push_back(rnd.next(1, m));
        }
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", values.at(rnd.next(0, k - 1)), " \n"[i == n - 1]);
        }
    }
}
