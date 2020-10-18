#include <cstdint>
#include <cstdio>
#include <map>
#include <vector>

using u64 = uint64_t;

int pow_mod(int a, int n, int p) {
  int result = 1;
  while (n) {
    if (n & 1) {
      result = (u64)result * a % p;
    }
    a = (u64)a * a % p;
    n >>= 1;
  }
  return result;
}

bool check_primitive_root(int w, int n, int p) {
  if (n % 2 == 0 && pow_mod(w, (p - 1) / 2, p) == 1) {
    return false;
  }
  if (n % 3 == 0 && pow_mod(w, (p - 1) / 3, p) == 1) {
    return false;
  }
  return true;
}

void add(int &x, int a, int p) {
  x += a;
  if (x >= p) {
    x -= p;
  }
}

int get_exp(int n) {
  int x = 0;
  while (n % 2 == 0) {
    x++, n /= 2;
  }
  return x;
}

std::vector<int> revbin(int n, const std::vector<int> &a) {
  std::vector<int> result(n);
  int x = get_exp(n);
  for (int i = 0; i < n; ++i) {
    int out = i % 3;
    int in = i / 3;
    for (int j = 0; j < x; ++j) {
      out = out * 2 + (in % 2);
      in /= 2;
    }
    result[out] = a[i];
  }
  return result;
}

int main() {
  int n, p, z;
  while (scanf("%d%d%d", &n, &p, &z) == 3) {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    int w = 1;
    while (!check_primitive_root(w, n, p)) {
      w++;
    }
    w = pow_mod(w, (p - 1) / n, p);
    a = revbin(n, a);
    int m = 1;
    while (n % (m * 2) == 0) {
      int g = pow_mod(w, n / (m * 2), p);
      for (int i = 0; i < n; i += m * 2) {
        int twiddle = 1;
        for (int r = i; r < i + m; ++r) {
          int tmp = (u64)twiddle * a[r + m] % p;
          a[r + m] = a[r];
          add(a[r + m], p - tmp, p);
          add(a[r], tmp, p);
          twiddle = (u64)twiddle * g % p;
        }
      }
      m *= 2;
    }
    int w1 = pow_mod(w, n / 3, p);
    int w2 = (u64)w1 * w1 % p;
    {
      int g = pow_mod(w, n / (m * 3), p);
      for (int i = 0; i < n; i += m * 3) {
        int twiddle = 1;
        for (int r = i; r < i + m; ++r) {
          int twiddle2 = (u64)twiddle * twiddle % p;
          // a[r], a[r + m], a[r + m + m]
          int y = (u64)twiddle * a[r + m] % p;
          int z = (u64)twiddle2 * a[r + m * 2] % p;
          a[r + m] = (a[r] + (u64)w1 * y + (u64)w2 * z) % p;
          a[r + m * 2] = (a[r] + (u64)w2 * y + (u64)w1 * z) % p;
          a[r] = ((u64)a[r] + y + z) % p;
          twiddle = (u64)twiddle * g % p;
        }
      }
    }
    std::map<int, int> result;
    for (int i = 0, z = 1; i < n; ++i) {
      result[z] = a[i];
      z = (u64)z * w % p;
    }
    for (int i = 0, zz = 1; i < n; ++i) {
      printf("%d%c", result[zz], " \n"[i + 1 == n]);
      zz = (u64)zz * z % p;
    }
  }
}
