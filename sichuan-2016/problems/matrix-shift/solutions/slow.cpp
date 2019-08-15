#include <algorithm>
#include <cstdio>
#include <vector>

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int m = n;
    std::vector<std::vector<int>> state(n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            state[i].push_back(i * m + j);
        }
    }
    while (q --) {
        int t, l, r, x;
        scanf("%d%d%d%d", &t, &l, &r, &x);
        if (t == 1) {
            for (int i = l; i <= r; ++ i) {
                std::rotate(state[i].begin(), state[i].begin() + (x % m), state[i].end());
            }
        } else if (t == 2) {
            for (int j = l; j <= r; ++ j) {
                std::vector<int> v;
                for (int i = 0; i < n; ++ i) {
                    v.push_back(state[i][j]);
                }
                std::rotate(v.begin(), v.begin() + (x % n), v.end());
                for (int i = 0; i < n; ++ i) {
                    state[i][j] = v[i];
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            printf("%d%c", state[i][j], " \n"[j == m - 1]);
        }
    }
}
