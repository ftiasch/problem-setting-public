#include <bits/stdc++.h>

const int N = 1000;

int n, m, result;
char map[N][N + 1];

void dfs(int idx, int cnt)
{
    // if (cnt + (n * m - idx) / 3 <= result) {
    //     return;
    // }
    if (idx == n * m) {
        result = std::max(result, cnt);
        return;
    }
    int i = idx / m;
    int j = idx % m;
    dfs(idx + 1, cnt);
    if (i + 1 < n && j + 2 < m && map[i][j] == '^' && map[i + 1][j + 1] == 'v' && map[i][j + 2] == '^') {
        map[i][j] = map[i + 1][j + 1] = map[i][j + 2] = ' ';
        dfs(idx + 1, cnt + 1);
        map[i][j] = '^'; map[i + 1][j + 1] = 'v'; map[i][j + 2] = '^';
    }
    if (i > 0 && j + 2 < m && map[i][j] == 'v' && map[i - 1][j + 1] == '^' && map[i][j + 2] == 'v') {
        map[i][j] = ' '; map[i - 1][j + 1] = ' '; map[i][j + 2] = ' ';
        dfs(idx + 1, cnt + 1);
        map[i][j] = 'v'; map[i - 1][j + 1] = '^'; map[i][j + 2] = 'v';
    }
    if (i + 2 < n && j + 1 < m && map[i][j] == '<' && map[i + 1][j + 1] == '>' && map[i + 2][j] == '<') {
        map[i][j] = ' '; map[i + 1][j + 1] = ' '; map[i + 2][j] = ' ';
        dfs(idx + 1, cnt + 1);
        map[i][j] = '<'; map[i + 1][j + 1] = '>'; map[i + 2][j] = '<';
    }
    if (i + 2 < n && j > 0 && map[i][j] == '>' && map[i + 1][j - 1] == '<' && map[i + 2][j] == '>') {
        map[i][j] = ' '; map[i + 1][j - 1] = ' '; map[i + 2][j] = ' ';
        dfs(idx + 1, cnt + 1);
        map[i][j] = '>'; map[i + 1][j - 1] = '<'; map[i + 2][j] = '>';
    }
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; ++ i) {
            scanf("%s", map[i]);
        }
        result = 0;
        dfs(0, 0);
        printf("%d\n", result);
    }
}
