#include <cstdio>
#include <cstring>
#include <stdexcept>

const int N = 50;

int n, m;
char grid[N + 2][N + 2];
bool marked[N + 2][N + 2];

void dfs(int x, int y) {
  if (x < 0 || x > n + 1 || y < 0 || y > m + 1 || grid[x][y] == 'o' ||
      marked[x][y]) {
    return;
  }
  marked[x][y] = true;
  dfs(x - 1, y);
  dfs(x + 1, y);
  dfs(x, y - 1);
  dfs(x, y + 1);
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int j = 0; j <= m + 1; ++j) {
      grid[0][j] = grid[n + 1][j] = '.';
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%s", grid[i] + 1);
      grid[i][0] = grid[i][m + 1] = '.';
    }
    int holes = -1;
    memset(marked, 0, sizeof(marked));
    for (int i = 0; i <= n + 1; ++i) {
      for (int j = 0; j <= m + 1; ++j) {
        if (grid[i][j] == '.' && !marked[i][j]) {
          dfs(i, j);
          holes++;
        }
      }
    }
    if (holes != 2 && holes != 3) {
      throw std::runtime_error("");
    }
    puts(holes == 2 ? "2020" : "2018");
  }
}
