#include <bits/stdc++.h>

using LL = long long;

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> c(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &c[i]);
        }
        std::vector<int> a(m), b(m);
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d", &a[i], &b[i]);
            a[i] --, b[i] --;
        }
        std::sort(c.begin(), c.end());
        LL result = std::numeric_limits<LL>::max();
        do {
            LL sum = 0;
            for (int i = 0; i < m; ++ i) {
                sum += std::abs(c[a[i]] - c[b[i]]);
            }
            result = std::min(result, sum);
        } while (std::next_permutation(c.begin(), c.end()));
        std::cout << result << std::endl;
    }
}
