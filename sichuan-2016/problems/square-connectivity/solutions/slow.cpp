#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m, l;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<int>> graph(n);
    for (int _ = 0; _ < m; ++ _) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
        std::vector<int> label(n << 1, -1);
        for (int s = 0; s < n << 1; ++ s) {
            if (!~label[s]) {
                std::queue<int> queue;
                queue.push(s);
                label[s] = s;
                while (!queue.empty()) {
                    int u = queue.front() >> 1;
                    int p = (queue.front() & 1) ^ 1;
                    queue.pop();
                    for (int v : graph.at(u)) {
                        int vv = v << 1 | p;
                        if (!~label[vv]) {
                            label[vv] = s;
                            queue.push(vv);
                        }
                    }
                }
            }
        }
        long long result = 0;
        for (int u = 0; u < n; ++ u) {
            for (int v = 0; v < u; ++ v) {
                result += label[u << 1] == label[v << 1 | 1];
            }
        }
        std::cout << result << "\n";
    }
    std::cout << std::flush;
    return 0;
}
