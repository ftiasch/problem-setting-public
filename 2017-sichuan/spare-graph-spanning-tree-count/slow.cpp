#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>

const int N = 200;

// {{{ https://github.com/zimpha/algorithmic-library/blob/master/mathematics/det-mod.cc
int det_mod(int n, int m, int mat[][N]) {
    using LL = long long;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][j] %= m;
    LL ret = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j)
            for (; mat[j][i]; ret = -ret) {
                LL t = mat[i][i] / mat[j][i];
                for (int k = i; k < n; ++k) {
                    mat[i][k] = (mat[i][k] - mat[j][k] * t) % m;
                    std::swap(mat[j][k], mat[i][k]);
                }
            }
        if (mat[i][i] == 0) return 0;
        ret = ret * mat[i][i] % m;
    }
    if (ret < 0) ret += m;
    return (int)ret;
}
// }}}

const int MOD = (int)1e9 + 7;

int mat[N][N];

void add(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        assert(n < N);
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < m; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            add(mat[a][a], 1);
            add(mat[b][b], 1);
            add(mat[a][b], MOD - 1);
            add(mat[b][a], MOD - 1);
        }
        printf("%d\n", det_mod(n - 1, MOD, mat));
    }
}
