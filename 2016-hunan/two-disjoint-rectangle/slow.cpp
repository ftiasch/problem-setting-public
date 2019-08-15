#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>

const int MOD = 1e9 + 7;

bool valid(const std::vector<std::vector<int>>& sum, int x1, int x2, int y1, int y2)
{
    x2 ++;
    y2 ++;
    return sum[x1][y1] + sum[x2][y2] == sum[x2][y1] + sum[x1][y2];
}

bool intersect(int x1, int x2, int y1, int y2)
{
    return std::max(x1, y1) <= std::min(x2, y2);
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<std::vector<char>> board(n, std::vector<char>(m + 1));
        for (int i = 0; i < n; ++ i) {
            scanf("%s", board[i].data());
        }
        std::vector<std::vector<int>> sum(n + 1, std::vector<int>(m + 1));
        for (int i = n - 1; i >= 0; -- i) {
            for (int j = m - 1; j >= 0; -- j) {
                sum[i][j] = board[i][j] == '1';
                sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
            }
        }
        using T = std::tuple<int, int, int, int>;
        std::vector<T> tuples;
        for (int x1 = 0; x1 < n; ++ x1) {
            for (int x2 = x1; x2 < n; ++ x2) {
                for (int y1 = 0; y1 < m; ++ y1) {
                    for (int y2 = y1; y2 < m; ++ y2) {
                        if (valid(sum, x1, x2, y1, y2)) {
                            tuples.emplace_back(x1, x2, y1, y2);
                        }
                    }
                }
            }
        }
        int result = 0;
        int parity = 0;
        for (auto&& p : tuples) {
            for (auto&& q : tuples) {
                if (intersect(std::get<0>(p), std::get<1>(p), std::get<0>(q), std::get<1>(q)) && 
                    intersect(std::get<2>(p), std::get<3>(p), std::get<2>(q), std::get<3>(q))) {
                    continue;
                }
                if (parity ^= 1) {
                    result ++;
                    if (result >= MOD) {
                        result -= MOD;
                    }
                }
            }
        }
        printf("%d\n", result);
    }
}
