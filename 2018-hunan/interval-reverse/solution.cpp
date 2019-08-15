#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

int main() {
    int n, m, q;
    while (scanf("%d%d%d", &n, &m, &q) == 3) {
        std::vector<int> a(m), b(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a[i], &b[i]);
            a[i]--;
        }
        std::vector<std::tuple<int, int, int>> queries;
        for (int i = 0, t; i < q; ++i) {
            scanf("%d", &t);
            t--;
            queries.emplace_back(t % m, t / m, i);
        }
        std::sort(queries.begin(), queries.end());
        std::vector<int> full(n), ifull(n);
        std::iota(full.begin(), full.end(), 0);
        for (int i = 0; i < m; ++i) {
            std::reverse(full.data() + a[i], full.data() + b[i]);
        }
        for (int i = 0; i < n; ++i) {
            ifull[full[i]] = i;
        }
        std::vector<bool> visited(n);
        std::vector<int> id(n), pos(n), lens;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            int j = i;
            int len = 0;
            do {
                visited[j] = true;
                id[j] = lens.size();
                pos[j] = len++;
                j = ifull[j];
            } while (j != i);
            lens.push_back(len);
        }
        std::vector<int> order(n);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](int i, int j) {
            return lens[id[i]] < lens[id[j]];
        });
        std::vector<int> result(q);
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 0);
        int curtime = -1;
        std::vector<int> count(n), time(n);
        int qb = 0;
        for (int i = 0; i < m; ++i) {
            std::reverse(perm.data() + a[i], perm.data() + b[i]);
            int qe = qb;
            while (qe < q && std::get<0>(queries[qe]) == i) {
                qe++;
            }
            int last_len = 0;
            auto flush = [&]() {
                if (last_len) {
                    for (int k = qb; k < qe; ++ k) {
                        int r = std::get<1>(queries[k]) % last_len;
                        if (time[r] == curtime) {
                            result[std::get<2>(queries[k])] += count[r];
                        }
                    }
                }
                curtime ++;
            };
            for (int j : order) {
                auto &c = id[j];
                if (id[perm[j]] != c) {
                    continue;
                }
                if (lens[c] != last_len) {
                    flush();
                    last_len = lens[c];
                }
                int delta = (pos[perm[j]] + lens[c] - pos[j]) % lens[c];
                if (time[delta] != curtime) {
                    time[delta] = curtime;
                    count[delta] = 0;
                }
                count[delta] ++;
            }
            flush();
            qb = qe;
        }
        for (int i = 0; i < q; ++i) {
            printf("%d\n", result[i]);
        }
    }
}
