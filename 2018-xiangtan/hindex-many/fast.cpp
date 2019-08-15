#include <bits/stdc++.h>

const int N = 100001;

int get_id(int l, int r)
{
    return l + r | l != r;
}

int a[N];
std::vector<int> idxs[N << 1];

void insert(int l, int r, int v, int k)
{
    idxs[get_id(l, r)].push_back(k);
    if (l < r) {
        int m = l + r >> 1;
        if (v <= m) {
            insert(l, m, v, k);
        } else {
            insert(m + 1, r, v, k);
        }
    }
}

int count(std::vector<int>& v, int r) // < r
{
    return std::lower_bound(v.begin(), v.end(), r) - v.begin();
}

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        for (int i = 0; i <= n + n; ++ i) {
            idxs[i].clear();
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
            insert(0, n, a[i], i);
        }
        while (q --) {
            int a, b;
            scanf("%d%d", &a, &b);
            int l = 0;
            int r = n;
            int cnt = 0;
            while (l < r) {
                int m = l + r >> 1;
                int id = get_id(m + 1, r);
                int tmp = count(idxs[id], b) - count(idxs[id], a - 1);
                if (cnt + tmp >= m + 1) {
                    l = m + 1;
                } else {
                    cnt += tmp;
                    r = m;
                }
            }
            printf("%d\n", r);
        }
    }
}
