#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

using i64 = long long;

i64 mst(int n, int m, const std::vector<int> &a, std::vector<int> &b,
        std::vector<i64> &w) {
  std::vector<int> idx(m), dsu(n);
  for (int i = 0; i < n; ++i)
    dsu[i] = i;
  for (int i = 0; i < m; ++i)
    idx[i] = i;
  std::function<int(int)> root = [&](int x) {
    if (x != dsu[x])
      dsu[x] = root(dsu[x]);
    return dsu[x];
  };
  std::sort(idx.begin(), idx.end(), [&](int x, int y) { return w[x] < w[y]; });
  i64 ret = 0;
  for (auto &e : idx) {
    int u = root(a[e]), v = root(b[e]);
    if (u != v)
      ret += w[e], dsu[u] = v;
  }
  return ret;
}

int main() {
  int n, m, l, r;
  while (scanf("%d%d%d%d", &n, &m, &l, &r) == 4) {
    std::vector<int> u(m), v(m);
    std::vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d%d", &u[i], &v[i], &a[i], &b[i]);
      --u[i], --v[i];
    }
    std::vector<i64> w(m);
    for (int i = 0; i < m; ++i)
      w[i] = (i64)b[i] * l + a[i];
    i64 ret_l = mst(n, m, u, v, w);
    for (int i = 0; i < m; ++i)
      w[i] = (i64)b[i] * r + a[i];
    i64 ret_r = mst(n, m, u, v, w);
    printf("%lld\n", std::min(ret_l, ret_r));
  }
  return 0;
}
