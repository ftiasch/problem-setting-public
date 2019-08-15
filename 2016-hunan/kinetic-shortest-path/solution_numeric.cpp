#include <algorithm>
#include <cstdio>
#include <functional>
#include <utility>
#include <vector>

typedef std::pair<int, int> Line;

const double INF = 1e10;
const double EPS = 1e-9;

int main()
{
    int n, m, t;
    while (scanf("%d%d%d", &n, &m, &t) == 3) {
        std::vector<std::vector<Line>> graph(n, std::vector<Line>(n, {-1, 0}));
        for (int _ = 0; _ < m; ++ _) {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            a --;
            b --;
            graph.at(a).at(b) = {c, d};
        }
        auto shortest_path = [&](double t) {
            std::vector<std::vector<double>> d(n, std::vector<double>(n, INF));
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < n; ++ j) {
                    auto&& e = graph.at(i).at(j);
                    if (~e.first) {
                        d.at(i).at(j) = e.first * t + e.second;
                    }
                }
            }
            for (int k = 0; k < n; ++ k) {
                for (int i = 0; i < n; ++ i) {
                    for (int j = 0; j < n; ++ j) {
                        d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
            return d[0][n - 1];
        };
        std::function<double(double, double, double, double)> recur = [&](double l, double ly, double r, double ry) {
            double m = 0.5 * (l + r);
            double my = shortest_path(m);
            if (my <= 0.5 * (ly + ry) + EPS) {
                return my * (r - l);
            }
            return recur(l, ly, m, my) + recur(m, my, r, ry);
        };
        printf("%.8f\n", recur(0, shortest_path(0), t, shortest_path(t)) / t);
    }
}
