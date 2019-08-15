#include "testlib.h"

struct Entry
{
    int t, x, y;
};

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = std::atoi(argv[1]);
    int N = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    while (T --) {
        int n = rnd.wnext(1, N, w);
        int m = rnd.wnext(1, N, w);
        std::vector<Entry> order;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (i + 1 < n && j + 2 < m) {
                    order.push_back(Entry { 0, i, j });
                    order.push_back(Entry { 1, i, j });
                }
                if (i + 2 < n && j + 1 < m) {
                    order.push_back(Entry { 2, i, j });
                    order.push_back(Entry { 3, i, j });
                }
            }
        }
        shuffle(order.begin(), order.end());
        std::vector<std::vector<char>> map(n, std::vector<char>(m + 1, '\0'));
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                map[i][j] = "<>^v"[rnd.next(0, 3)];
            }
        }
        for (auto&& e : order) {
            int x = e.x, y = e.y;
            if (e.t == 0) {
                map[x][y] = map[x][y + 2] = '^';
                map[x + 1][y + 1] = 'v';
            } else if (e.t == 1) {
                map[x + 1][y] = map[x + 1][y + 2] = 'v';
                map[x][y + 1] = '^';
            } else if (e.t == 2) {
                map[x][y] = map[x + 2][y] = '<';
                map[x + 1][y + 1] = '>';
            } else if (e.t == 3) {
                map[x][y + 1] = map[x + 2][y + 1] = '>';
                map[x + 1][y] = '<';
            }
        }
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; ++ i) {
            puts(map[i].data());
        }
    }
}
