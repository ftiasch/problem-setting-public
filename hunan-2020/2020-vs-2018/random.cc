#include "testlib.h"

#include <array>
#include <cstdio>
#include <ctime>
#include <utility>
#include <vector>

using Coordinates = std::array<std::pair<int, int>, 4>;

auto generate_coordinates(int n, int m, int a, int b)
    -> std::pair<bool, Coordinates> {
  std::vector<std::vector<bool>> used(n, std::vector<bool>(m));
  Coordinates coordinates;
  for (int k = 0; k < 4; ++k) {
    std::vector<std::pair<int, int>> candidates;
    for (int i = 0; i + a <= n; ++i) {
      for (int j = 0; j + b <= m; ++j) {
        bool ok = true;
        for (int x = -1; x <= a; ++x) {
          for (int y = -1; y <= b; ++y) {
            int xx = i + x;
            int yy = j + y;
            ok &= xx < 0 || xx >= n || yy < 0 || yy >= m || !used[xx][yy];
          }
        }
        if (ok) {
          candidates.emplace_back(i, j);
        }
      }
    }
    if (candidates.empty()) {
      return {false, coordinates};
    }
    coordinates[k] = candidates[rnd.next(0, (int)candidates.size() - 1)];
    for (int x = 0; x < a; ++x) {
      for (int y = 0; y < b; ++y) {
        used[coordinates[k].first + x][coordinates[k].second + y] = true;
      }
    }
  }
  return {true, coordinates};
}

template <int digit>
void draw(int a, int b, std::pair<int, int> p,
          std::vector<std::vector<char>> &canvas) {
  int x = p.first;
  int y = p.second;
  if (digit == 2) {
    int a2 = rnd.next(5, a);
    int a1 = rnd.next(3, a2 - 2);
    int bb = rnd.next(3, b);
    for (int i = 0; i < a1; ++i) {
      canvas[x + i][y + bb - 1] = 'o';
    }
    for (int i = a1; i < a2; ++i) {
      canvas[x + i][y] = 'o';
    }
    for (int j = 0; j < bb; ++j) {
      canvas[x][y + j] = canvas[x + a1 - 1][y + j] = canvas[x + a2 - 1][y + j] =
          'o';
    }
  } else if (digit == 0) {
    int aa = rnd.next(3, a);
    int bb = rnd.next(3, b);
    for (int i = 0; i < aa; ++i) {
      canvas[x + i][y] = canvas[x + i][y + bb - 1] = 'o';
    }
    for (int j = 0; j < bb; ++j) {
      canvas[x][y + j] = canvas[x + aa - 1][y + j] = 'o';
    }
  } else if (digit == 1) {
    int aa = rnd.next(3, a);
    for (int i = 0; i < aa; ++i) {
      canvas[x + i][y] = 'o';
    }
  } else if (digit == 8) {
    int a2 = rnd.next(5, a);
    int a1 = rnd.next(3, a2 - 2);
    int bb = rnd.next(3, b);
    for (int i = 0; i < a2; ++i) {
      canvas[x + i][y] = canvas[x + i][y + bb - 1] = 'o';
    }
    for (int j = 0; j < bb; ++j) {
      canvas[x][y + j] = canvas[x + a1 - 1][y + j] = canvas[x + a2 - 1][y + j] =
          'o';
    }
  }
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int T = std::atoi(argv[1]);
  const int n = std::atoi(argv[2]);
  const int m = std::atoi(argv[3]);
  while (T--) {
    int w = rnd.next(0, std::min(n - 3, m - 5));
    while (true) {
      const int a = 5 + w;
      const int b = 3 + w;
      bool ok;
      Coordinates coordinates;
      std::tie(ok, coordinates) = generate_coordinates(n, m, a, b);
      if (ok) {
        std::vector<std::vector<char>> canvas(n, std::vector<char>(m + 1, '.'));
        for (int i = 0; i < n; ++i) {
          canvas[i][m] = '\0';
        }
        if (rnd.next(0, 1)) {
          // fprintf(stderr, "2018\n");
          draw<2>(a, b, coordinates[0], canvas);
          draw<0>(a, b, coordinates[1], canvas);
          draw<1>(a, b, coordinates[2], canvas);
          draw<8>(a, b, coordinates[3], canvas);
        } else {
          // fprintf(stderr, "2020\n");
          draw<2>(a, b, coordinates[0], canvas);
          draw<0>(a, b, coordinates[1], canvas);
          draw<2>(a, b, coordinates[2], canvas);
          draw<0>(a, b, coordinates[3], canvas);
        }
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; ++i) {
          printf("%s\n", canvas[i].data());
        }
        break;
      } else {
        w = std::max(w - 1, 0);
      }
    }
  }
}
