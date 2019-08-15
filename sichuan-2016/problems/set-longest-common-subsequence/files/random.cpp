#include "testlib.h"

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int l = std::atoi(argv[2]);
    int w_segment = std::atoi(argv[3]);
    int w_value = std::atoi(argv[4]);
    std::vector<int> values;
    for (int i = 0; i < l; ++ i) {
        values.push_back(i + 1);
    }
    shuffle(values.begin(), values.end());
    std::vector<int> lengths(n);
    for (int _ = 0; _ < n; ++ _) {
        lengths.at(rnd.wnext(0, n - 1, w_segment)) ++;
    }
    std::sort(lengths.begin(), lengths.end(), std::greater<int>());
    while (!lengths.back()) {
        lengths.pop_back();
    }
    shuffle(lengths.begin(), lengths.end());
    int m = lengths.size();
    printf("%d %d %d\n", n, m, l);
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", values.at(rnd.wnext(0, l - 1, w_value)), " \n"[i == n - 1]);
    }
    for (int i = 0; i < m; ++ i) {
        printf("%d", lengths.at(i));
        for (int j = 0; j < lengths.at(i); ++ j) {
            printf(" %d", values.at(rnd.wnext(0, l - 1, w_value)));
        }
        puts("");
    }
}
