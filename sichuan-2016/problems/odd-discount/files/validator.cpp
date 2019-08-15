#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, 20);
    inf.readSpace();
    int m = inf.readInt(1, 100000);
    inf.readEoln();
    for (int _ = 0; _ < m; ++ _) {
        inf.readInt(1, 10000);
        inf.readSpace();
        int size = inf.readInt(1, n);
        std::vector<int> elements;
        for (int __ = 0; __ < size; ++ __) {
            inf.readSpace();
            elements.push_back(inf.readInt(1, n));
        }
        inf.readEoln();
        std::sort(elements.begin(), elements.end());
        ensure(static_cast<int>(std::unique(elements.begin(), elements.end()) - elements.begin()) == size);
    }
    inf.readEof();
}
