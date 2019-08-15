#include "testlib.h"

#include <algorithm>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>

int find(std::vector<int>& parent, int u)
{
    if (parent.at(u) != u) {
        parent.at(u) = find(parent, parent.at(u));
    }
    return parent.at(u);
}

std::pair<int, int> generate_pair(int n, int w)
{
    int a = rnd.next(0, n - 1);
    int d = rnd.wnext(1, n, w);
    return {a, (a + d) % n};
}

std::vector<std::pair<int, int>> generate(int n, int m, int w)
{
    std::vector<std::pair<int, int>> graph;
    std::vector<int> parent(n);
    std::iota(parent.begin(), parent.end(), 0);
    int a, b;
    for (int _ = 0; _ < n - 1; ++ _) {
        int c = -1;
        int d = -1;
        while (c == d) {
            std::tie(a, b) = generate_pair(n, w);
            c = find(parent, a);
            d = find(parent, b);
        }
        graph.emplace_back(a, b);
        parent.at(c) = d;
    }
    for (int _ = n - 1; _ < m; ++ _) {
        graph.push_back(generate_pair(n, w));
    }
    shuffle(graph.begin(), graph.end());
    return graph;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int m = std::atoi(argv[2]);
    int c = std::atoi(argv[3]);
    int w = std::atoi(argv[4]);
    printf("%d %d\n", n, m);
    std::vector<int> label(n);
    std::iota(label.begin(), label.end(), 1);
    shuffle(label.begin(), label.end());
    for (auto&& edge : generate(n, m, w)) {
        int l = rnd.next(1, n);
        printf("%d %d %d %d\n", label.at(edge.first), label.at(edge.second), rnd.next(1, c), l);
    }
}
