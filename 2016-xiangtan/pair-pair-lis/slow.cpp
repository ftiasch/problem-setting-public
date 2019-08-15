#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<std::pair<int, int>> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d", &a.at(i).first, &a.at(i).second);
        }
        std::vector<long long> count(5);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int v[] = {a.at(i).first, a.at(i).second, a.at(j).first, a.at(j).second};
                int length = 0;
                int f[] = {1, 1, 1, 1};
                for (int y = 0; y < 4; ++ y) {
                    for (int x = 0; x < y; ++ x) {
                        if (v[x] < v[y]) {
                            f[y] = std::max(f[y], f[x] + 1);
                        }
                    }
                    length = std::max(length, f[y]);
                }
                count.at(length) ++;
            }
        }
        std::cout << count.at(1) << " " << count.at(2) << " " << count.at(3) << " " << count.at(4) << std::endl;
    }
}
