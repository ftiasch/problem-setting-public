#include <bits/stdc++.h>

const int MAX_LEN = 3;

struct Fenwick
{
    Fenwick(int n)
        : n(n), count(n)
    {
    }

    void add(int l, int r)
    {
        add_(l, 1);
        add_(r, -1);
    }

    int ask(int l)
    {
        int res = 0;
        for (; l >= 0; l -= ~l & l + 1) {
            res += count.at(l);
        }
        return res;
    }

private:
    void add_(int l, int v)
    {
        for (; l < n; l += ~l & l + 1) {
            count.at(l) += v;
        }
    }

    int n;
    std::vector<int> count;
};

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        std::vector<Fenwick> trees;
        for (int l = 0; l < MAX_LEN && l <= n; ++ l) {
            trees.emplace_back(n - l);
        }
        while (q --) {
            int t, l, r;
            scanf("%d%d%d", &t, &l, &r);
            l --;
            if (t == 1) {
                for (int i = 0; i < MAX_LEN && i <= r - l; ++ i) {
                    trees.at(i).add(l, r - i);
                }
            } else {
                printf("%d\n", trees.at(r - l - 1).ask(l));
            }
        }
    }
}
