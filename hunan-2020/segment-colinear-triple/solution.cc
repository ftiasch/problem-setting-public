#include <cstdint>
#include <cstdio>

struct Point {
  int x, y;
};

Point operator-(const Point &a, const Point &b) {
  return {a.x - b.x, a.y - b.y};
}

long long det(const Point &a, const Point &b) {
  return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool check(const Point &a, const Point &b, const Point &c) {
  return det(b - a, c - a) > 0;
}

int main() {
  int x1[3], x2[3], y[3];
  while (scanf("%d%d%d", x1, x2, y) == 3) {
    for (int i = 1; i < 3; ++i) {
      scanf("%d%d%d", x1 + i, x2 + i, y + i);
    }
    puts(check({x1[0], y[0]}, {x1[2], y[2]}, {x2[1], y[1]}) ||
                 check({x2[2], y[2]}, {x2[0], y[0]}, {x1[1], y[1]})
             ? "No"
             : "Yes");
  }
}
