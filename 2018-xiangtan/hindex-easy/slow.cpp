#include <bits/stdc++.h>

const int N = 200001;

int n, a[N];

bool check(int h)
{
    long long cnt = 0;
    for (int i = h; i <= n; ++ i) {
        cnt += a[i];
    }
    return cnt >= h;
}

int main()
{
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i <= n; ++ i) {
            scanf("%d", a + i);
        }
        int h = n;
        while (!check(h)) {
            h --;
        }
        printf("%d\n", h);
    }
}
