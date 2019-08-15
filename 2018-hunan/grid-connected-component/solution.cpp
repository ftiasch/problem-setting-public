#include <bits/stdc++.h>

struct Segments
{
    Segments(int n)
    {
        s[-1] = -1;
        s[n + 2] = n + 2;
    }

    void add(int l, int r)
    {
        while (true) {
            auto it = s.lower_bound(l);
            if (it->second > r) {
                break;
            }
            update(-1, it);
        }
        auto it2 = s.upper_bound(l);
        auto it = it2;
        it --;
        if (r <= it->second) {
            return;
        }
        if (it->second >= l - 1) {
            l = it->first;
            update(-1, it);
        }
        if (it2->first <= r + 1) {
            r = it2->second;
            update(-1, it2);
        }
        update(1, s.emplace(l, r).first);
    }

    void update(int sign, const std::map<int, int>::iterator& it) {
        int l = it->second - it->first + 1;
        cnt += sign * l;
        adj += sign * (l - 1);
        if (sign < 0) {
            s.erase(it);
        }
    }

    int cnt = 0, adj = 0;
    std::map<int, int> s;
};

int main()
{
    int n, m, q;
    while (scanf("%d%d%d", &n, &m, &q) == 3) {
        std::vector<int> t(q), l(q), r(q);
        for (int i = 0; i < q; ++ i) {
            scanf("%d%d%d", &t[i], &l[i], &r[i]);
        }
        Segments hor(n), ver(m);
        for (int i = 0; i < q; ++ i) {
            (t[i] == 1 ? hor : ver).add(l[i], r[i]);
            long long result = 1LL * n * m;
            result -= (m - 1LL) * hor.cnt;
            result -= (n - 1LL) * ver.cnt;
            result += std::max((hor.cnt - 1LL), 0LL) * std::max((ver.cnt - 1LL), 0LL);
            printf("%lld\n", result);
        }
    }
}
