#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

const int N = 100000;

int color[N], head[N], to[N - 1 << 1], next[N - 1 << 1], total[N], count[N], size[N], prefer[N], intersection, result[N - 1];

void prepare(int p, int u)
{
    size[u] = 1;
    std::pair<int, int> best(0, -1);
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
        int v = to[iterator];
        if (v != p) {
            prepare(u, v);
            best = std::max(best, std::make_pair(size[v], iterator));
            size[u] += size[v];
        }
    }
    prefer[u] = best.second;
}

int value(int c)
{
    return 0 < count[c] && count[c] < total[c];
}

void update(int c, int delta)
{
    intersection -= value(c);
    count[c] += delta;
    intersection += value(c);
}

void clear(int p, int u, int add = -1)
{
    update(color[u], add);
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
        int v = to[iterator];
        if (v != p) {
            clear(u, v, add);
        }
    }
}

void dfs(int p, int u)
{
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
        int v = to[iterator];
        if (v != p && iterator != prefer[u]) {
            dfs(u, v);
            result[iterator >> 1] = intersection;
            clear(u, v);
        }
    }
    if (~prefer[u]) {
        dfs(u, to[prefer[u]]);
        result[prefer[u] >> 1] = intersection;
    }
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
        int v = to[iterator];
        if (v != p && iterator != prefer[u]) {
            clear(u, v, 1);
        }
    }
    update(color[u], 1);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        memset(total, 0, sizeof(*total) * n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", color + i);
            color[i] --;
            total[color[i]] ++;
        }
        memset(head, -1, sizeof(*head) * n);
        for (int i = 0; i < n - 1 << 1; ++ i) {
            scanf("%d", to + i);
            to[i] --;
        }
        for (int i = 0; i < n - 1 << 1; ++ i) {
            auto& ref = head[to[i ^ 1]];
            next[i] = ref;
            ref = i;
        }
        prepare(-1, 0);
        intersection = 0;
        memset(count, 0, sizeof(*count) * n);
        dfs(-1, 0);
        for (int i = 0; i < n - 1; ++ i) {
            printf("%d\n", result[i]);
        }
    }
}
