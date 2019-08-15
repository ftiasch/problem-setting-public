#include <algorithm>
#include <cstdio>
#include <functional>
#include <numeric>
#include <vector>

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<int> p(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &p.at(i));
            p.at(i) --;
        }
        std::vector<int> q(n);
        std::iota(q.begin(), q.end(), 0);
        int result = 0;
        do {
            bool valid = true;
            for (int i = 0; i < n; ++ i) {
                if (~p.at(i)) {
                    valid &= p.at(i) == q.at(i);
                }
            }
            if (valid) {
                std::vector<int> length(n);
                for (int i = 0; i < n; ++ i) {
                    length.at(i) = 1;
                    for (int j = 0; j < i; ++ j) {
                        if (q.at(j) < q.at(i)) {
                            length.at(i) = std::max(length.at(i), length.at(j) + 1);
                        }
                    }
                }
                result += *std::max_element(length.begin(), length.end()) == n - 1;
            }
        } while (std::next_permutation(q.begin(), q.end()));
        printf("%d\n", result);
    }
}
