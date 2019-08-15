#include <cstdio>
#include <cstring>
#include <climits>
#include <numeric>
#include <map>
#include <queue>
#include <utility>
#include <vector>

int find(std::vector<int>& parent, int u)
{
    if (parent.at(u) != u) {
        parent.at(u) = find(parent, parent.at(u));
    }
    return parent.at(u);
}

std::vector<int> bfs(const std::vector<std::vector<int>>& cap, int s)
{
    int n = cap.size();
    std::vector<int> lv(n, -1);
    lv.at(s) = 0;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++ v) {
            if (cap.at(u).at(v) > 0 && lv.at(v) == -1) {
                lv.at(v) = lv.at(u) + 1;
                q.push(v);
            }
        }
    }
    return lv;
}

int dfs(const std::vector<int>& lv, std::vector<std::vector<int>>& cap, std::vector<int>& cur, int u, int t, int left)
{
    if (u == t) {
        return left;
    }
    int n = cap.size();
    int delta = 0;
    for (auto& v = cur.at(u); v < n; ++ v) {
        if (cap.at(u).at(v) > 0 && lv.at(v) == lv.at(u) + 1) {
            int tmp = dfs(lv, cap, cur, v, t, std::min(left - delta, cap.at(u).at(v)));
            delta += tmp;
            cap.at(u).at(v) -= tmp;
            cap.at(v).at(u) += tmp;
            if (delta == left) {
                break;
            }
        }
    }
    return delta;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::map<int, std::vector<std::pair<int, int>>> edges;
        for (int i = 0; i < m; ++ i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges[c].emplace_back(a - 1, b - 1);
        }
        int result = INT_MAX;
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);
        for (auto&& iterator : edges) {
            auto&& es = iterator.second;
            std::vector<bool> mark(n);
            std::vector<std::vector<int>> cap(n, std::vector<int>(n));
            for (auto&& e : es) {
                auto&& a = find(parent, e.first);
                auto&& b = find(parent, e.second);
                if (a != b) {
                    mark.at(a) = mark.at(b) = true;
                    cap.at(a).at(b) ++;
                    cap.at(b).at(a) ++;
                }
            }
            for (int s = 0; s < n; ++ s) {
                if (mark.at(s)) {
                    auto lv = bfs(cap, s);
                    int t = 0;
                    while (t < s && lv.at(t) == -1) {
                        t ++;
                    }
                    if (t == s) {
                        for (t = s + 1; t < n; ++ t) {
                            if (lv.at(t) != -1) {
                                auto fl = cap;
                                int cut = 0;
                                while (true) {
                                    auto lv = bfs(fl, s);
                                    if (lv.at(t) == -1) {
                                        break;
                                    }
                                    std::vector<int> cur(n);
                                    cut += dfs(lv, fl, cur, s, t, INT_MAX);
                                }
                                result = std::min(result, cut);
                            }
                        }
                    }
                }
            }
            for (auto&& e : es) {
                auto&& a = find(parent, e.first);
                auto&& b = find(parent, e.second);
                if (a != b) {
                    parent.at(a) = b;
                }
            }
        }
        printf("%d\n", result);
    }
}
