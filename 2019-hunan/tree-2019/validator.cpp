#include <bits/stdc++.h>
#include <testlib.h>

static const int MOD = 2019;

struct Val {
  Val(int n) : parent(n) {
    std::iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < n - 1; ++i) {
      int a = inf.readInt(1, n) - 1;
      inf.readSpace();
      int b = inf.readInt(1, n) - 1;
      inf.readSpace();
      inf.readInt(0, MOD - 1);
      inf.readEoln();
      ensure(find(a) != find(b));
      parent[find(a)] = find(b);
    }
  }

  int find(int u) {
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  std::vector<int> parent;
};

int main() {
  registerValidation();
  int sum = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 20000);
    inf.readEoln();
    Val{n};
    ensure((sum += n) <= 100000);
  }
  inf.readEof();
}
