#include <cstdio>

using i64 = long long;

struct point {
  i64 x, y;
  point(i64 x = 0, i64 y = 0) : x(x), y(y) {}
  point operator-(const point &rhs) const { return {x - rhs.x, y - rhs.y}; }
  i64 det(const point &rhs) const { return x * rhs.y - y * rhs.x; }
};

i64 sgn(i64 x) {
  if (x < 0)
    return -1;
  else
    return x > 0;
}

int main() {
  point u[3], v[3];
  i64 a[3], b[3], y[3];
  while (scanf("%lld%lld%lld", &a[0], &b[0], &y[0]) == 3) {
    scanf("%lld%lld%lld", &a[1], &b[1], &y[1]);
    scanf("%lld%lld%lld", &a[2], &b[2], &y[2]);
    for (int i = 0; i < 3; ++i) {
      u[i] = {a[i], y[i]};
      v[i] = {b[i], y[i]};
    }

    auto check = [&](point &s, point &t) {
      for (int i = 0; i < 3; ++i) {
        auto st = t - s, su = u[i] - s, sv = v[i] - s;
        if (sgn(st.det(su)) * sgn(st.det(sv)) > 0)
          return false;
      }
      return true;
    };

    bool found = false;
    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        found |= check(u[i], u[j]);
        found |= check(u[i], v[j]);
        found |= check(v[i], u[j]);
        found |= check(v[i], v[j]);
      }
    }
    if (found)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
