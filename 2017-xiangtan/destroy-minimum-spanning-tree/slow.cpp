#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <climits>
#include <tuple>
#include <vector>

struct Edge
{
    Edge(int a, int b, int c) : a(a), b(b), c(c) {}

    int a, b, c;
};

bool operator < (const Edge& a, const Edge& b)
{
    return a.c < b.c;
}

int find(std::vector<int>& parent, int u)
{
    if (parent.at(u) == -1) {
        return u;
    }
    return parent.at(u) = find(parent, parent.at(u));
}

std::pair<int, std::vector<int>> mst(int n, const std::vector<Edge>& edges, const std::vector<int>& state)
{
    int result = 0;
    std::vector<int> candidates;
    std::vector<int> parent(n, -1);
    for (int i = 0; i < static_cast<int>(edges.size()); ++ i) {
        if (state.at(i) == 1) {
            continue;
        }
        int a = find(parent, edges.at(i).a);
        int b = find(parent, edges.at(i).b);
        if (a != b) {
            result += edges.at(i).c;
            parent.at(a) = b;
            candidates.push_back(i);
        }
    }
    if (static_cast<int>(candidates.size()) < n - 1) {
        return {INT_MAX, candidates};
    }
    return {result, candidates};
}

void search(int n, int pre_mst, const std::vector<Edge>& edges, int& best, int depth, std::vector<int> state)
{
    if (depth >= best) {
        return;
    }
    int cur_mst;
    std::vector<int> candidates;
    std::tie(cur_mst, candidates) = mst(n, edges, state);
    if (pre_mst < cur_mst) {
        best = std::min(best, depth);
    } else {
        for (auto&& c : candidates) {
            assert(state.at(c) != 1);
            if (state.at(c) == -1) {
                state.at(c) = 1;
                search(n, pre_mst, edges, best, depth + 1, state);
                state.at(c) = 0;
            }
        }
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<Edge> edges;
        for (int i = 0; i < m; ++ i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges.emplace_back(a - 1, b - 1, c);
        }
        std::sort(edges.begin(), edges.end());
        std::vector<int> state(m, -1);
        int pre_mst = mst(n, edges, state).first;
        int best = INT_MAX;
        search(n, pre_mst, edges, best, 0, state);
        printf("%d\n", best);
    }
}
