#include <bits/stdc++.h>

int solve(int n, int a)
{
    auto check = [&](int h)
    {
        for (int x = 0; x + h <= n; ++ x) {
            int used = h + x;
            for (int i = 0; i < h; ++ i) {
                int need = std::max(h - a - x, 0);
                if (need && !a) {
                    used = n + 1;
                } else if (need) {
                    used += (need + a - 1) / a;
                }
            }
            if (used <= n) {
                return true;
            }
        }
        return false;
    };

    int h = n;
    while (h && !check(h)) {
        h --;
    }
    return h;
}

int main()
{
    int n, a;
    while (scanf("%d%d", &n, &a) == 2) {
        printf("%d\n", solve(n, a));
    }
}
