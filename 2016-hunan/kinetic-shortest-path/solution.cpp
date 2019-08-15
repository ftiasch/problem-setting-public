#include <algorithm>
#include <cstdio>
#include <functional>
#include <utility>
#include <vector>

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

typedef std::pair<int, int> Line;

bool check(const Line& a, const Line& b, const Line& c)
{
    return (b.second - a.second) * (b.first - c.first) < (c.second - b.second) * (a.first - b.first);
}

double intersection_x(const Line& a, const Line& b)
{
    return (double)(b.second - a.second) / (a.first - b.first);
}

void dfs(const std::vector<std::vector<Line> >& graph, std::vector<bool>& visited, std::vector<Line>& paths, int n, int u, int k, int b)
{
    visited.at(u) = true;
    if (u == n - 1) {
        paths.push_back(std::make_pair(k, b));
    } else {
        for (int v = 0; v < n; ++ v) {
            Line edge = graph.at(u).at(v);
            if (!visited.at(v) && ~edge.first) {
                dfs(graph, visited, paths, n, v, k + edge.first, b + edge.second);
            }
        }
    }
    visited.at(u) = false;
}

int main()
{
    int n, m, t;
    while (scanf("%d%d%d", &n, &m, &t) == 3) {
        std::vector<std::vector<Line> > graph(n, std::vector<Line>(n, std::make_pair(-1, 0)));
        for (int _ = 0; _ < m; ++ _) {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            a --;
            b --;
            graph.at(a).at(b) = std::make_pair(c, d);
        }
        std::vector<bool> visited(n);
        std::vector<Line> paths;
        dfs(graph, visited, paths, n, 0, 0, 0);
        std::sort(paths.begin(), paths.end(), std::greater<std::pair<int, int> >());
        std::vector<Line> planes;
        foreach (iterator, paths) {
            Line& p = *iterator;
            while ((int)planes.size() >= 2 && !check(planes[planes.size() - 2], planes.back(), p)) {
                planes.pop_back();
            }
            planes.push_back(p);
        }
        std::vector<double> xs;
        for (int i = 1; i < static_cast<int>(planes.size()); ++ i) {
            xs.push_back(intersection_x(planes.at(i - 1), planes.at(i)));
        }
        double result = 0.;
        for (int i = 0; i < (int)planes.size(); ++ i) {
            double low = 0.;
            if (i) {
                low = std::max(low, xs[i - 1]);
            }
            double high = t;
            if (i + 1 < (int)planes.size()) {
                high = std::min(high, xs[i]);
            }
            if (low <= high) {
                double x = 0.5 * (low + high);
                result += (planes[i].first * x + planes[i].second) * (high - low);
            }
        }
        printf("%.8f\n", result / t);
    }
}
