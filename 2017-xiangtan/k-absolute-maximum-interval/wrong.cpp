#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main()
{
    int n, m, c;
    while (scanf("%d%d%d", &n, &m, &c) == 3) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        std::vector<long long> s(n + 1);
        for (int i = 0; i < n; ++ i) {
            s.at(i + 1) = s.at(i) + a.at(i);
        }
        std::sort(s.begin(), s.end());
        long long result = 0;
        for (int i = 0; i < m; ++ i) {
            result += s.at(n - i) - s.at(i) - c;
        }
        std::cout << result << std::endl;
    }
}
