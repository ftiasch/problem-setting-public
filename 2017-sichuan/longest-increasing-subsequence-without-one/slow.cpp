#include <algorithm>
#include <cstdio>
#include <climits>

const int N = 5000;

int a[N], g[N + 1];

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
        }
        for (int ban = 0; ban < n; ++ ban) {
            int sum = 0;
            int max_f = 1;
            g[0] = INT_MIN;
            for (int i = 0; i < n; ++ i) {
                if (i == ban) {
                    continue;
                }
                int f = std::lower_bound(g, g + max_f, a[i]) - g;
                if (f == max_f) {
                    g[f] = a[i];
                    max_f ++;
                } else {
                    g[f] = std::min(g[f], a[i]);
                }
                sum ^= f * f;
            }
            printf("%d%c", sum, " \n"[ban == n - 1]);
        }
    }
}
