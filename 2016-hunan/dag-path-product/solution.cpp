#include <cstdio>
#include <cstring>
#include <vector>

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

const int MOD = (int)1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d", &a.at(i), &b.at(i));
        }
        std::vector<int> degree(n);
        std::vector<std::vector<int> > graph(n);
        for (int i = 0; i < m; ++ i) {
            int u, v;
            scanf("%d%d", &u, &v);
            u --;
            v --;
            degree.at(v) ++;
            graph.at(u).push_back(v);
        }
        std::vector<int> queue;
        for (int i = 0; i < n; ++ i) {
            if (!degree.at(i)) {
                queue.push_back(i);
            }
        }
        std::vector<int> ways(n);
        for (int head = 0; head < n; ++ head) {
            int u = queue.at(head);
            int w = ways.at(u);
            update(w, a.at(u));
            foreach (iterator, graph.at(u)) {
                int& v = *iterator;
                update(ways.at(v), w);
                if (!-- degree.at(v)) {
                    queue.push_back(v);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++ i) {
            update(result, (long long)ways.at(i) * b.at(i) % MOD);
        }
        printf("%d\n", result);
    }
}
