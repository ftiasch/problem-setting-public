#include <cstdio>
#include <vector>

const int MOD = (int)1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

struct Fenwick
{
    Fenwick(int n) : n(n), sum(n)
    {
    }

    void add(int k, int v)
    {
        for (; k < n; k += ~k & k + 1) {
            update(sum.at(k), v);
        }
    }

    int ask(int l, int r) const
    {
        return (ask_(r - 1) + MOD - ask_(l)) % MOD;
    }

    int ask_(int k) const
    {
        int result = 0;
        for (; k >= 0; k -= ~k & k + 1) {
            update(result, sum.at(k));
        }
        return result;
    }

    int n;
    std::vector<int> sum;
};

int signum(int x)
{
    return x < 0 ? -1 : x > 0;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; ++ i) {
            int x;
            scanf("%d", &x);
            a.at(i) = 2 * x - 1;
        }
        for (int i = 0; i < m; ++ i) {
            scanf("%d", &b.at(i));
        }
        std::vector<std::vector<int>> dp(m, std::vector<int>(m + 2));
        for (int i = 0; i < m; ++ i) {
            for (int o = 0; o <= m + 1; ++ o) {
                if (a.at(n - 1) == signum(b.at(i) - o)) {
                    dp.at(i).at(o) = 1;
                }
            }
        }
        for (int i = n - 2; i >= 0; -- i) {
            std::vector<Fenwick> sum(m + 2, m + 2);
            for (int j = m - 1; j >= 0; -- j) {
                std::vector<int> tmp(m + 2);
                for (int o = 0; o <= m + 1; ++ o) {
                    if (a.at(i) == signum(b.at(j) - o)) {
                        int l = b.at(j);
                        int r = o;
                        if (l > r) {
                            std::swap(l, r);
                        }
                        update(tmp.at(o), sum.at(o).ask(l, r));
                        update(tmp.at(o), sum.at(b.at(j)).ask(l, r));
                        // printf("%d %d %d %d\n", i, b.at(j), o, tmp.at(o));
                    }
                }
                for (int o = 0; o <= m + 1; ++ o) {
                    if (a.at(i + 1) == signum(b.at(j) - o)) {
                        sum.at(o).add(b.at(j), dp.at(j).at(o));
                    }
                }
                dp.at(j) = tmp;
            }
        }
        int result = 0;
        for (int j = 0; j < m; ++ j) {
            if (a.at(0) == 1) {
                update(result, dp.at(j).at(0));
            } else {
                update(result, dp.at(j).at(m + 1));
            }
        }
        printf("%d\n", result);
    }
}
