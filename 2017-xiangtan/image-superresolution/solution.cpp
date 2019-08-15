#include <cstdio>

const int N = 10;

char map[N][N + 1];

int main()
{
    int n, m, a, b;
    while (scanf("%d%d%d%d", &n, &m, &a, &b) == 4) {
        for (int i = 0; i < n; ++ i) {
            scanf("%s", map[i]);
        }
        for (int i = 0; i < n * a; ++ i) {
            for (int j = 0; j < m * b; ++ j) {
                putchar(map[i / a][j / b]);
            }
            puts("");
        }
    }
}
