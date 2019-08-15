#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, (int)1e5);
    inf.readSpace();
    int m = inf.readInt(1, (int)1e5);
    inf.readEoln();
    for (int i = 0; i < n; ++ i) {
        inf.readInt(0, (int)1e9);
        inf.readSpace();
        inf.readInt(0, (int)1e9);
        inf.readEoln();
    }
    std::vector<int> degree(n);
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++ i) {
        int a = inf.readInt(1, n) - 1;
        inf.readSpace();
        int b = inf.readInt(1, n) - 1;
        inf.readEoln();
        degree.at(b) ++;
        graph.at(a).push_back(b);
    }
    inf.readEof();
    std::vector<int> queue;
    for (int i = 0; i < n; ++ i) {
        if (!degree.at(i)) {
            queue.push_back(i);
        }
    }
    for (int head = 0; head < n; ++ head) {
        ensure(head < static_cast<int>(queue.size()));
        auto u = queue.at(head);
        for (auto&& v : graph.at(u)) {
            if (!-- degree.at(v)) {
                queue.push_back(v);
            }
        }
    }
}
