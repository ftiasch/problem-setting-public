#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> group(std::vector<int> a)
{
    std::sort(a.begin(), a.end());
    std::vector<std::pair<int, int>> groups;
    int n = a.size();
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a.at(i) == a.at(j)) {
            j ++;
        }
        groups.emplace_back(a.at(i), j - i);
        i = j;
    }
    return groups;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        for (int i = 0; i < m; ++ i) {
            scanf("%d", &b.at(i));
        }
        int M = std::max(*std::max_element(a.begin(), a.end()), *std::max_element(b.begin(), b.end()));
        std::vector<int> s(M + 1);
        for (int i = 0, j = 0; i <= M; ++ i) {
            if ((j + 1) * (j + 1) <= i) {
                j ++;
            }
            s[i] = j;
        }
        auto ga = group(a);
        auto gb = group(b);
        long long result = 0.;
        for (auto&& i : ga) {
            for (auto&& j : gb) {
                result += (long long)s.at(std::abs(i.first - j.first)) * i.second * j.second;
            }
        }
        std::cout << result << std::endl;
    }
}
