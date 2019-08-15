#include <bits/stdc++.h>

struct Solver
{
    Solver(int n) : n(n), a(n), count(n), contrib(n), result(n), children(n) {}

    void run()
    {
        for (int i = 1, p; i < n; ++ i) {
            scanf("%d", &p);
            children[p - 1].push_back(i);
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
            a[i] --;
        }
        dfs(0, 0, 0);
        for (int i = 1; i < n; ++ i) {
            printf("%lld\n", result[i]);
        }
    }

    void dfs(int u, int distinct, long long cresult)
    {
        int c = a[u];
        int prev = contrib[c];
        cresult -= contrib[c];
        cresult += (contrib[c] = distinct);
        result[u] = cresult;
        distinct += count[c] == 0;
        count[c] ++;
        for (auto v : children[u]) {
            dfs(v, distinct, cresult);
        }
        count[c] --;
        contrib[c] = prev;
    }

    int n;
    std::vector<int> a, count, contrib;
    std::vector<long long> result;
    std::vector<std::vector<int>> children;
};


int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        Solver(n).run();
    }
}
