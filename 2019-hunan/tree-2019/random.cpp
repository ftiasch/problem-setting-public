#include <bits/stdc++.h>
#include <testlib.h>

namespace {
static std::vector<std::pair<int, int>> random_tree(int n, int w) {
  std::vector<int> parent(n, -1);
  std::function<int(int)> find = [&](int u) {
    return ~parent[u] ? parent[u] = find(parent[u]) : u;
  };
  std::vector<std::pair<int, int>> edges;
  for (auto _ = 0; _ < n - 1; ++_) {
    while (true) {
      auto a = rnd.next(0, n - 1);
      auto b = rnd.wnext(1, n - 1, w) % n;
      auto u = find(a);
      auto v = find(b);
      if (u != v) {
        if (rnd.next(0, 1)) {
          std::swap(a, b);
        }
        edges.emplace_back(a, b);
        parent[u] = v;
        break;
      }
    }
  }
  return edges;
}
} // namespace

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 5);
  int T = std::atoi(argv[1]);
  int N = std::atoi(argv[2]);
  int w = std::atoi(argv[3]);
  int m = std::atoi(argv[4]);
  while (T--) {
    int n = N < 0 ? rnd.next(1, -N) : N;
    printf("%d\n", n);
    for (auto &&e : random_tree(n, w)) {
      int w = rnd.next(0, m - 1);
      printf("%d %d %d\n", e.first + 1, e.second + 1, w);
    }
  }
}
