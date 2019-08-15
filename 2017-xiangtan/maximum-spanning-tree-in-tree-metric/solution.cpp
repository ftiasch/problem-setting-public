#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using Tree = std::vector<std::vector<std::pair<int, int>>>;
using LL = long long;

std::vector<LL> bfs(int n, const Tree& tree, int s)
{
    std::vector<int> q;
    std::vector<LL> d(n, -1);
    d.at(s) = 0;
    q.push_back(s);
    for (int head = 0; head < static_cast<int>(q.size()); ++ head) {
        auto u = q.at(head);
        for (auto&& edge : tree.at(u)) {
            auto&& v = edge.first;
            if (d.at(v) == -1) {
                d.at(v) = d.at(u) + edge.second;
                q.push_back(v);
            }
        }
    }
    return d;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        Tree tree(n);
        for (int i = 0; i < n - 1; ++ i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a --;
            b --;
            tree.at(a).emplace_back(b, c);
            tree.at(b).emplace_back(a, c);
        }
        auto d0 = bfs(n, tree, 0);
        auto a = std::max_element(d0.begin(), d0.end()) - d0.begin();
        auto da = bfs(n, tree, a);
        auto b = std::max_element(da.begin(), da.end()) - da.begin();
        auto db = bfs(n, tree, b);
        LL result = da.at(b);
        for (int i = 0; i < n; ++ i) {
            if (i != a && i != b) {
                result += std::max(da.at(i), db.at(i));
            }
        }
        std::cout << result << std::endl;
    }
}
