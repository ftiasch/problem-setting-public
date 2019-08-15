#include "testlib.h"

#include <functional>
#include <vector>

int main()
{
    registerValidation();
    int test_count = 0;
    while (!inf.eof()) {
        test_count ++;
        int n = inf.readInt(1, 100000, "n");
        inf.readEoln();
        std::vector<int> parent(n, -1);
        std::function<int(int)> find = [&](int u) {
            return ~parent[u] ? parent[u] = find(parent[u]) : u;
        };
        for (int _ = 0; _ < n - 1; ++ _) {
            int a = inf.readInt(1, n) - 1;
            inf.readSpace();
            int b = inf.readInt(1, n) - 1;
            inf.readSpace();
            inf.readInt(1, (int)1e8);
            inf.readEoln();
            ensure(find(a) != find(b));
            parent.at(find(a)) = find(b);
        }
    }
    ensure(1 <= test_count && test_count <= 10);
    inf.readEof();
}
