#include <bits/stdc++.h>

struct Solver {
  Solver() {
    if (ok = static_cast<bool>(std::cin >> s)) {
      std::fill(visited.begin(), visited.end(), false);
      dfs(0);
      printf("%d\n", result);
    }
  }

  void dfs(int i) {
    if (i == static_cast<int>(s.size())) {
      result++;
    } else {
      int a = s[i] - '0';
      if (!visited[a]) {
        visited[a] = true;
        dfs(i + 1);
        visited[a] = false;
      }
      if (a != 0 && i + 2 <= static_cast<int>(s.size())) {
        int b = a * 10 + s[i + 1] - '0';
        if (!visited[b]) {
          visited[b] = true;
          dfs(i + 2);
          visited[b] = false;
        }
      }
    }
  }

  operator bool() const { return ok; }

  std::string s;
  bool ok;
  int result = 0;
  std::array<bool, 100> visited;
};

int main() {
  while (static_cast<bool>(Solver())) {
  }
}
