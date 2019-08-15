#include <bits/stdc++.h>

int main()
{
    int n, m, q;
    while (scanf("%d%d%d", &n, &m, &q) == 3) {
        std::vector<int> a(m), b(m);
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d", &a[i], &b[i]);
            a[i] --;
        }
        while (q --) {
            int t;
            scanf("%d", &t);
            std::vector<int> perm(n);
            std::iota(perm.begin(), perm.end(), 0);
            for (int i = 0; i < t; ++ i) {
                std::reverse(perm.data() + a[i % m], perm.data() + b[i % m]);
            }
            int result = 0;
            for (int i = 0; i < n; ++ i) {
                result += perm[i] == i;
            }
            printf("%d\n", result);
        }
    }
}
