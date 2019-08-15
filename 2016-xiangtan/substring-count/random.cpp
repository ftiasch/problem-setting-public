#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int q = std::atoi(argv[2]);
    std::string alphabet = argv[3];
    int w = std::atoi(argv[3]);
    std::vector<int> lengths(n);
    for (int i = 0; i < n; ++ i) {
        lengths.at(rnd.wnext(0, n - 1, w)) ++;
    }
    std::sort(lengths.begin(), lengths.end(), std::greater<int>());
    lengths.resize(q);
    shuffle(lengths.begin(), lengths.end());
    std::string text = rnd.next(format("[%s]{%d}", alphabet.c_str(), n));
    printf("%d %d\n%s\n", n, q, text.c_str());
    for (int i = 0; i < q; ++ i) {
        if (lengths[i]) {
            if (rnd.next(0, 1)) {
                int start = rnd.next(0, n - lengths[i]);
                printf("0 %s\n", text.substr(start, lengths[i]).c_str());
            } else {
                printf("0 %s\n", rnd.next(format("[%s]{%d}", alphabet.c_str(), lengths[i])).c_str());
            }
        } else {
            int index = rnd.next(0, n - 1);
            char c = alphabet[rnd.next(0, static_cast<int>(alphabet.size()) - 1)];
            text.at(index) = c;
            printf("%d %c\n", index + 1, c);
        }
    }
    return 0;
}
