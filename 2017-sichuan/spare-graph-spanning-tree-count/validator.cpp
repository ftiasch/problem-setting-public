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
        inf.readSpace();
        int m = inf.readInt(n + 1, n + 99, "m");
        inf.readEoln();
        std::vector<int> parent(n, -1);
        std::function<int(int)> find = [&](int u) {
            return ~parent[u] ? parent[u] = find(parent[u]) : u;
        };
        for (int _ = 0; _ < m; ++ _) {
            int a = inf.readInt(1, n) - 1;
            inf.readSpace();
            int b = inf.readInt(1, n) - 1;
            inf.readEoln();
            if (find(a) != find(b)) {
                parent.at(find(a)) = find(b);
            }
        }
        for (int i = 0; i < n; ++ i) {
            ensure(find(0) == find(i));
        }
    }
    ensure(1 <= test_count && test_count <= 10);
    inf.readEof();
}
