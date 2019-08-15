#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int k = std::atoi(argv[1]);
    int w = std::atoi(argv[2]);
    for (int i = 0; i < k; ++ i) {
        printf("%d%c", rnd.next(-w, w), " \n"[i == k - 1]);
    }
    std::vector<int> low, high;
    for (int i = 0; i < k; ++ i) {
        int a, b;
        do {
            a = rnd.next(-w, w);
            b = rnd.next(-w, w);
        } while (a == b);
        if (a > b) {
            std::swap(a, b);
        }
        low.push_back(a);
        high.push_back(b);
    }
    for (int i = 0; i < k; ++ i) {
        printf("%d%c", low.at(i), " \n"[i == k - 1]);
    }
    for (int i = 0; i < k; ++ i) {
        printf("%d%c", high.at(i), " \n"[i == k - 1]);
    }
}
