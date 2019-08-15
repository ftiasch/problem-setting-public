#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

const int MOD = (int)1e9 + 7;

void update(int &x, int a)
{
    x = std::min(x, a);
}

int cost(int n)
{
    if (n < 0) {
        return 0;
    }
    return (n + 2) / 3;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> minimum(m + 1, 0);
        for (int i = 0; i < n; ++ i) {
            int a;
            scanf("%d", &a);
            std::vector<int> new_minimum(m + 1, INT_MAX);
            for (int j = 0; j <= m; ++ j) {
                for (int k = 0; j + k <= m; ++ k) {
                    update(new_minimum[j + k], minimum[j] + cost(a - 2 * k));
                }
            }
            minimum.swap(new_minimum);
        }
        int result = 0;
        for (int i = 0; i <= m; ++ i) {
            result += minimum.at(i);
            if (result >= MOD) {
                result -= MOD;
            }
        }
        printf("%d\n", result);
    }
}
