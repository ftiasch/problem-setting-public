#include <bits/stdc++.h>

const int N = 100000;

int a[N], lis[N], best[N + 1];

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
        }
        best[0] = 0;
        for (int i = 1; i <= n; ++ i) {
            best[i] = n;
        }
        for (int i = 0; i < n; ++ i) {
            if (a[i]) {
                lis[i] = std::lower_bound(best, best + (n + 1), a[i]) - best;
                best[lis[i]] = std::min(best[lis[i]], a[i]);
            } else {
                lis[i] = 0;
            }
        }
        long long result = 0;
        for (int x = 1; x <= n; ++ x) {
            best[0] = 0;
            for (int i = 1; i <= n; ++ i) {
                best[i] = n;
            }
            int gmax = 0;
            for (int i = 0; i < n; ++ i) {
                int val = a[i] ? a[i] : x;
                int newlis = best[lis[i]] < val ? lis[i] + 1 : lis[i];
                best[newlis] = std::min(best[newlis], val);
                if (!a[i]) {
                    lis[i] = newlis;
                }
                gmax = std::max(gmax, newlis);
            }
            result += 1LL * x * gmax;
        }
        printf("%lld\n", result);
    }
}
