#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

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
        long long result = 0.;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                result += s.at(std::abs(a.at(i) - b.at(j)));
            }
        }
        std::cout << result << std::endl;
    }
}
