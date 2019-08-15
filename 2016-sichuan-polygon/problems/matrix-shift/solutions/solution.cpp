#include <cstdio>
#include <vector>

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int m = n;
    std::vector<int> down(n * m), right(n * m);
    auto loc = [&](int x, int y) {
        return x * m + y;
    };
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            down.at(loc(i, j)) = loc((i + 1) % n, j);
            right.at(loc(i, j)) = loc(i, (j + 1) % m);
        }
    }
    int origin = loc(0, 0);
    auto jump = [&](const std::vector<int>& link, int p, int k) {
        for (int _ = 0; _ < k; ++ _) {
            p = link[p];
        }
        return p;
    };
    auto shift = [&](int n, int m, std::vector<int>& down, std::vector<int>& right, int l, int r, int x) -> void {
        auto relink = [&](int p, int q) {
            for (int i = 0; i < m; ++ i) {
                down[p] = q;
                p = right[p];
                q = right[q];
            }
        };
        if (l == 0 && r == n) {
            return;
        }
        x %= m;
        int p = jump(down, origin, l);
        int q = jump(right, p, x);
        p = jump(down, p, n - 1);
        int p2 = jump(down, p, r - l + 1);
        int q2 = jump(down, q, r - l - 1);
        relink(p, q);
        relink(q2, p2);
    };
    while (q --) {
        int t, l, r, x;
        scanf("%d%d%d%d", &t, &l, &r, &x);
        r ++;
        if (t == 1) {
            shift(n, m, down, right, l, r, x);
            if (!l) {
                origin = jump(right, origin, x % m);
            }
        } else {
            shift(m, n, right, down, l, r, x);
            if (!l) {
                origin = jump(down, origin, x % n);
            }
        }
    }
    for (int i = 0, p = origin; i < n; ++ i) {
        for (int j = 0, q = p; j < m; ++ j) {
            printf("%d%c", q, " \n"[j == m - 1]);
            q = right[q];
        }
        p = down[p];
    }
}
