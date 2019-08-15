#include <cstdio>
#include <numeric>
#include <vector>

void update(int &x, int a)
{
    if (!~x || a < x) {
        x = a;
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<std::vector<int>> graph(n, std::vector<int>(n, -1));
        std::vector<int> best(n, -1);
        for (int _ = 0; _ < m; ++ _) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a --;
            b --;
            update(graph.at(a).at(b), c);
        }
        std::vector<int> permutation(n);
        std::iota(permutation.begin(), permutation.end(), 0);
        int result = -1;
        do {
            int sum = 0;
            for (int i = 0; i < n - 1 && ~sum; ++ i) {
                int u = permutation.at(i);
                int v = permutation.at(i + 1);
                int e = graph.at(u).at(v);
                if (~e) {
                    sum += e;
                } else {
                    sum = -1;
                }
            }
            if (~sum) {
                update(result, sum);
            }
        } while (std::next_permutation(permutation.begin(), permutation.end()));
        printf("%d\n", result);
    }
    return 0;
}
