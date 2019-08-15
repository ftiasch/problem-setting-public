#include <cassert>
#include <cstdio>
#include <vector>

// #define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug(...)

const int MOD = (int)1e9 + 7;

void add(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int inv(int a)
{
    return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int det(std::vector<std::vector<int>>& mat, int n)
{
    int result = 1;
    for (int j = 0; j < n; ++ j) {
        int pv = j;
        while (pv < n && mat.at(pv).at(j) == 0) {
            pv ++;
        }
        assert(pv < n);
        if (j < pv) {
            result = result * (MOD - 1LL) % MOD;
            std::swap(mat.at(j), mat.at(pv));
        }
        result = 1LL * result * mat.at(j).at(j) % MOD;
        int inv_ = inv(mat.at(j).at(j));
        for (int i = pv + 1; i < n; ++ i) {
            if (mat.at(i).at(j) != 0) {
                auto t = 1LL * inv_ * mat.at(i).at(j) % MOD;
                for (int k = j; k < n; ++ k) {
                    add(mat.at(i).at(k), MOD - mat.at(j).at(k) * t % MOD);
                }
            }
        }
    }
    return result;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> ends(m << 1);
        for (int i = 0; i < m << 1; ++ i) {
            scanf("%d", &ends.at(i));
            ends.at(i) --;
        }
        std::vector<std::vector<int>> graph(n);
        for (int i = 0; i < m << 1; ++ i) {
            graph.at(ends.at(i ^ 1)).push_back(i);
        }
        std::vector<int> degree(n), queue;
        for (int i = 0; i < n; ++ i) {
            degree.at(i) = graph.at(i).size();
            if (degree.at(i) == 1) {
                queue.push_back(i);
            }
        }
        for (int head = 0; head < static_cast<int>(queue.size()); ++ head) {
            auto u = queue.at(head);
            for (auto&& e : graph.at(u)) {
                auto&& v = ends.at(e);
                if ((degree.at(v) --) == 2) {
                    queue.push_back(v);
                }
            }
        }
        for (auto&& v : queue) {
            debug("%d, ", v + 1);
        }
        debug("queue\n");
        int nn = 0;
        std::vector<int> new_label(n, -1), neighbour(n, 1);
        for (int i = 0; i < n; ++ i) {
            if (degree.at(i) == 2) {
                for (auto&& e : graph.at(i)) {
                    if (degree.at(ends.at(e)) > 1) {
                        neighbour.at(i) ^= e;
                    }
                }
            }
            if (degree.at(i) > 2) {
                new_label.at(i) = nn ++;
            }
        }
        debug("n = %d\n", nn);
        for (int i = 0; i < n; ++ i) {
            debug("%d, ", degree.at(i));
        }
        debug("degree\n");
        int multiplier = 1;
        std::vector<std::vector<int>> laplacian(nn, std::vector<int>(nn));
        for (int s = 0; s < n; ++ s) {
            if (~new_label.at(s)) {
                for (auto&& se : graph.at(s)) {
                    if (degree.at(ends.at(se)) > 1) {
                        int e = se;
                        int t = ends.at(e);
                        int count = 1;
                        while (new_label.at(t) == -1) {
                            assert(degree.at(t) == 2);
                            e ^= neighbour.at(t);
                            t = ends.at(e);
                            count ++;
                        }
                        if (se <= (e ^ 1)) {
                            auto&& a = new_label.at(s);
                            auto&& b = new_label.at(t);
                            multiplier = 1LL * multiplier * count % MOD;
                            if (a != b) {
                                int weight = inv(count);
                                add(laplacian.at(a).at(a), weight);
                                add(laplacian.at(b).at(b), weight);
                                add(laplacian.at(a).at(b), MOD - weight);
                                add(laplacian.at(b).at(a), MOD - weight);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", 1LL * multiplier * det(laplacian, nn - 1) % MOD);
    }
}
