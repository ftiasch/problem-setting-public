#include "testlib.h"

std::vector<int> read(int k)
{
    std::vector<int> result;
    for (int i = 0; i < k; ++ i) {
        result.push_back(inf.readInt(-10000, 10000));
        if (i + 1 < k) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    return result;
}

int main()
{
    registerValidation();
    const int k = 3;
    read(k);
    std::vector<int> low = read(k);
    std::vector<int> high = read(k);
    for (int i = 0; i < k; ++ i) {
        ensure(low.at(i) < high.at(i));
    }
    inf.readEof();
}
