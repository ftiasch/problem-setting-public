#include <bits/stdc++.h>

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<int> parent(n, -1), a(n);
        for (int i = 1; i < n; ++ i) {
            scanf("%d", &parent[i]);
            parent[i] --;
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i < n; ++ i) {
            std::vector<int> b;
            for (int j = i; ~j; j = parent[j]) {
                b.push_back(a[j]);
            }
            std::set<std::pair<int, int>> elems;
            for (int j = 0; j < static_cast<int>(b.size()); ++ j) {
                for (int k = 0; k < j; ++ k) {
                    elems.emplace(b[j], b[k]);
                }
            }
            printf("%d\n", static_cast<int>(elems.size()));
        }
    }
}
