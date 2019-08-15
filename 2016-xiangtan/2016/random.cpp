#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    std::vector<std::vector<int>> candidates;
    for (int a = 0; a < 7; ++ a) {
        for (int b = 0; b < 7; ++ b) {
            for (int c = 0; c < 7; ++ c) {
                for (int d = 0; d < 7; ++ d) {
                    if ((a * d - b * c) % 7) {
                        candidates.push_back({a, b, c, d});
                    }
                }
            }
        }
    }
    shuffle(candidates.begin(), candidates.end());
    printf("%s\n", rnd.next(format("[1-9][0-9]{0,%d}", n - 1)).c_str());
    auto&& a = candidates.back();
    for (int i = 0; i < 4; ++ i) {
        printf("%d%c", a.at(i), " \n"[i & 1]);
    }
}
