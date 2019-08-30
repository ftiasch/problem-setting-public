#include <bits/stdc++.h>
#include <testlib.h>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 4);
  int T = std::atoi(argv[1]);
  int N = std::atoi(argv[2]);
  int M = std::atoi(argv[3]);
  while (T--) {
    int n = N < 0 ? rnd.next(2, -N) : N;
    int m = M < 0 ? rnd.next(1, -M) : M;
    printf("%d %d\n", n, m);
    std::vector<int> size(n, 1);
    std::vector<std::pair<int, int>> ops;
    for (int i = 0; i < m; ++i) {
      while (true) {
        int a = rnd.next(0, n - 1);
        int b = rnd.next(0, n - 1);
        if (a != b) {
          ops.emplace_back(a, b);
          size[a] += size[b];
          size[b] = 0;
          break;
        }
      }
    }
    std::vector<int> remap(n);
    std::iota(remap.begin(), remap.end(), 1);
    {
      int idx = std::max_element(size.begin(), size.end()) - size.begin();
      std::swap(remap[0], remap[idx]);
    }
    for (int i = 0; i < m; ++i) {
      printf("%d %d\n", remap[ops[i].first], remap[ops[i].second]);
    }
  }
}
