#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 500;

using B = std::bitset<N>;

B b[N];

int main()
{
    int n, m, q;
    while (scanf("%d%d%d", &n, &m, &q) == 3) {
        std::vector<std::vector<int>> graph(n);
        for (int i = 0; i < m; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            graph.at(a).push_back(b);
        }
        std::vector<int> color(n, 1);
        while (q --) {
            int v;
            scanf("%d", &v);
            v --;
            color.at(v) ^= 1;
            int result = 0;
            for (int i = n - 1; i >= 0; -- i) {
                if (color.at(i)) {
                    b[i].reset();
                    b[i].set(i);
                    for (auto&& j : graph.at(i)) {
                        if (color.at(j) && !b[i].test(j)) {
                            b[i] |= b[j];
                        }
                    }
                    for (int j = i + 1; j < n; ++ j) {
                        if (b[i].test(j)) {
                            result ++;
                        }
                    }
                }
            }
            printf("%d\n", result);
        }
    }
}
