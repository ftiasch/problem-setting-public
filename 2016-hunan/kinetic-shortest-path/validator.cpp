#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(2, 10);
    inf.readSpace();
    int m = inf.readInt(1, n * (n - 1));
    inf.readSpace();
    inf.readInt(1, 10000);
    inf.readEoln();
    std::vector<std::set<int>> edges(n);
    std::vector<std::vector<bool>> graph(n, std::vector<bool>(n));
    for (int _ = 0; _ < m; ++ _) {
        int a = inf.readInt(1, n) - 1;
        inf.readSpace();
        int b = inf.readInt(1, n) - 1;
        inf.readSpace();
        inf.readInt(0, 1000);
        inf.readSpace();
        inf.readInt(0, 1000);
        inf.readEoln();
        ensure(a != b);
        ensure(edges.at(a).insert(b).second);
        graph.at(a).at(b) = true;
    }
    for (int k = 0; k < n; ++ k) {
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
    ensure(graph.at(0).at(n - 1));
    inf.readEof();
}
