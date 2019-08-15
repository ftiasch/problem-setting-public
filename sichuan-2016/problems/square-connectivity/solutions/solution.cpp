#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <functional>
#include <numeric>
#include <vector>

struct Node
{
    Node(bool bipartite, int parent, int parity, int size_0, int size_1)
    : bipartite(bipartite)
    , parent(parent)
    , parity(parity)
    , size{size_0, size_1}
    {
    }

    long long count() const
    {
        if (bipartite) {
            return 1LL * size[0] * size[1];
        }
        long long n = size[0] + size[1];
        return n * (n - 1) >> 1;
    }

    bool bipartite;
    int parent;
    int parity;
    int size[2];
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<Node> nodes;
    for (int i = 0; i < n; ++ i) {
        nodes.emplace_back(true, i, 0, 1, 0);
    }
    std::function<int(int)> find = [&](int u) {
        if (nodes[u].parent != u) {
            int p = nodes[u].parent;
            nodes[u].parent = find(p);
            nodes[u].parity ^= nodes[p].parity;
        }
        return nodes[u].parent;
    };
    std::ios::sync_with_stdio(false);
    long long result = 0;
    for (int _ = 0; _ < m; ++ _) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        int u = find(a);
        int v = find(b);
        if (u == v) {
            if (nodes[a].parity == nodes[b].parity) {
                auto& r = nodes[u];
                result -= r.count();
                r.bipartite = false;
                result += r.count();
            }
        } else {
            result -= nodes[u].count();
            result -= nodes[v].count();
            nodes[u].bipartite &= nodes[v].bipartite;
            int parity = nodes[a].parity ^ 1 ^ nodes[b].parity;
            nodes[v].parity = parity;
            nodes[u].size[0] += nodes[v].size[parity];
            nodes[u].size[1] += nodes[v].size[parity ^ 1];
            nodes[v].parent = u;
            result += nodes[u].count();
        }
        std::cout << result << "\n";
    }
    std::cout << std::flush;
    return 0;
}
