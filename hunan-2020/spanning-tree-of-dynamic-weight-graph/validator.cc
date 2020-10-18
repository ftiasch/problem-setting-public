#include "testlib.h"
#include <functional>
#include <set>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  int sn = 0, sm = 0;
  while (!inf.eof()) {
    int n = inf.readInt(2, 100000, "n");
    inf.readSpace();
    int m = inf.readInt(n - 1, 200000, "n");
    inf.readSpace();
    int l = inf.readInt(0, 1000000, "l");
    inf.readSpace();
    inf.readInt(l, 1000000, "r");
    inf.readEoln();
    sn += n;
    sm += m;
    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i)
      parent[i] = i;
    std::function<int(int)> root = [&](int x) {
      if (x != parent[x])
        parent[x] = root(parent[x]);
      return parent[x];
    };

    int cnt = n;
    for (int i = 0; i < m; ++i) {
      int a = inf.readInt(1, n, format("u[%d]", i + 1));
      inf.readSpace();
      int b = inf.readInt(1, n, format("v[%d]", i + 1));
      inf.readSpace();
      inf.readInt(1, 1000000, format("a[%d]", i + 1));
      inf.readSpace();
      inf.readInt(-1000000, 1000000, format("b[%d]", i + 1));
      inf.readEoln();
      int u = root(a - 1), v = root(b - 1);
      if (u != v)
        --cnt, parent[u] = v;
      if (a > b)
        std::swap(a, b);
      ensuref(a != b, "no loops");
    }

    ensuref(cnt == 1, "input is a tree");
    ensuref(sn <= 1000000, "sum n <= 1000000");
    ensuref(sm <= 2000000, "sum m <= 2000000");
  }
  inf.readEof();
  return 0;
}
