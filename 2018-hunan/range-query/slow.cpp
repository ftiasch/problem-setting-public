#include <bits/stdc++.h>

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        std::vector<std::pair<int, int>> itvs;
        while (q --) {
            int t, l, r;
            scanf("%d%d%d", &t, &l, &r);
            if (t == 1) {
                itvs.emplace_back(l, r);
            } else {
                int result = 0;
                for (auto&& it : itvs) {
                    result += it.first <= l && r <= it.second;
                }
                printf("%d\n", result);
            }
        }
    }
}
