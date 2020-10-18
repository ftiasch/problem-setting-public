#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1e6 + 10;

char s[N];
int t[N], x[N], y[N];
int n;

bool check() {
  for (int i = 0; i < n; ++i) x[i] = t[i];
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n - i; ++j) {
      y[j] = std::abs(x[j + 1] - x[j]);
    }
    for (int j = 0; j < n - i; ++j) x[j] = y[j];
  }
  return x[0] == 1;
}

int dfs(int d) {
  if (d == n) return check();
  if (s[d] != '?') {
    t[d] = s[d] - '0';
    return dfs(d + 1);
  } else {
    int ret = 0;
    t[d] = 0;
    ret += dfs(d + 1);
    t[d] = 1;
    ret += dfs(d + 1);
    return ret;
  }
}

int main() {
  while (scanf("%s", s) == 1) {
    n = strlen(s);
    printf("%d\n", dfs(0));
  }
  return 0;
}
