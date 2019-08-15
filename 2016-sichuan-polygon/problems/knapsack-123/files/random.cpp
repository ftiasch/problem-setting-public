#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int m = std::atoi(argv[1]);
    int mask = std::atoi(argv[2]) % 27;
    std::vector<int> count;
    for (int _ = 0; _ < 3; ++ _) {
        count.push_back(mask % 3);
        mask /= 3;
    }
    for (int i = 0; i < 3; ++ i) {
        if (count[i] == 2) {
            count[i] = rnd.next(0, m);
        }
    }
    printf("%d %d %d\n", count[0], count[1], count[2]);
}
