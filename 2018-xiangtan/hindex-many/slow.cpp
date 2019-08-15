#include <bits/stdc++.h>

const int N = 100000;

int a[N], b[N];

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
        }
        while (q --) {
            int l, r;
            scanf("%d%d", &l, &r);
            l --;
            int m = r - l;
            memcpy(b, a + l, sizeof(int) * m);
            std::sort(b, b + m);
            int h = b[m - 1] + 1;
            int i = m;
            while (m - i < h) {
                h --;
                while (i > 0 && b[i - 1] == h) {
                    i --;
                }
            }
            printf("%d\n", h);
        }
    }
}
