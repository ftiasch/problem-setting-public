#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 100001;

int a[N], fw[N], bw[N], best[N], delta[N];

void compute(int n, int* a, int* bw)
{
    best[0] = 0;
    for (int i = 1; i <= n; ++ i) {
        best[i] = n;
    }
    for (int i = 0; i < n; ++ i) {
        if (a[i]) {
            bw[i] = std::lower_bound(best, best + (n + 1), a[i]) - best;
            best[bw[i]] = std::min(best[bw[i]], a[i]);
        } else {
            bw[i] = 0;
        }
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
        }
        compute(n, a, bw);
        std::reverse(a, a + n);
        for (int i = 0; i < n; ++ i) {
            if (a[i]) {
                a[i] = n + 1 - a[i];
            }
        }
        compute(n, a, fw);
        std::reverse(a, a + n);
        for (int i = 0; i < n; ++ i) {
            if (a[i]) {
                a[i] = n + 1 - a[i];
            }
        }
        std::reverse(fw, fw + n);
        int global = *std::max_element(bw, bw + n);
        a[n] = n + 1, fw[n] = 0;
        for (int i = 0; i <= n; ++ i) {
            best[i] = n;
        }
        memset(delta, 0, sizeof(*delta) * (n + 1));
        for (int i = 0; i <= n; ++ i) {
            if (a[i]) {
                if (best[global - fw[i]] + 1 <= a[i] - 1) {
                    delta[best[global - fw[i]] + 1] ++;
                    delta[a[i]] --;
                }
            } else {
                int j = i - 1;
                for (; j >= 0 && a[j]; -- j) {
                    best[bw[j]] = std::min(best[bw[j]], a[j]);
                }
                if (j == -1) {
                    best[0] = std::min(best[0], 0);
                }
            }
        }
        int sum = 0;
        long long result = 0;
        for (int i = 1; i <= n; ++ i) {
            sum += delta[i];
            result += 1LL * i * (sum ? global + 1 : global);
        }
        std::cout << result << "\n";
    }
}
