#include <bits/stdc++.h>

#include "testlib.h"

std::vector<std::pair<int, int>> random_tree(int n, int w)
{
    std::vector<int> parent(n, -1);
    std::function<int(int)> find = [&](int u) {
        return ~parent[u] ? parent[u] = find(parent[u]) : u;
    };
    std::vector<std::pair<int, int>> edges;
    for (auto _ = 0; _ < n - 1; ++ _) {
        while (true) {
            auto a = rnd.next(0, n - 1);
            auto b = (a + rnd.wnext(1, n - 1, w)) % n;
            auto u = find(a);
            auto v = find(b);
            if (u != v) {
                if (rnd.next(0, 1)) {
                    std::swap(a, b);
                }
                edges.emplace_back(a, b);
                parent[u] = v;
                break;
            }
        }
    }
    return edges;
}

void dfs(const std::vector<std::vector<int>>& tree, std::vector<int>& parent, int& count, int p, int q, int u)
{
    parent[count] = q;
    q = count ++;
    for (int v : tree[u]) {
        if (v != p) {
            dfs(tree, parent, count, u, q, v);
        }
    }
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int n = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    int m = std::atoi(argv[4]);
    while (T --) {
        printf("%d\n", n);
        std::vector<std::vector<int>> tree(n);
        for (auto&& e : random_tree(n, w)) {
            tree[e.first].push_back(e.second);
            tree[e.second].push_back(e.first);
        }
        std::vector<int> parent(n);
        int count = 0;
        dfs(tree, parent, count, -1, -1, 0);
        for (int i = 1; i < n; ++ i) {
            printf("%d%c", w < 0 ? i : parent[i] + 1, " \n"[i == n - 1]);
        }
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", m < 0 ? i + 1 : rnd.next(1, m), " \n"[i == n - 1]);
        }
    }
}
