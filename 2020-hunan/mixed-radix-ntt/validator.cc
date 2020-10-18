#include "testlib.h"

#include <cstdint>

using u64 = uint64_t;

bool check(int n) {
  while (n % 2 == 0) {
    n /= 2;
  }
  return n == 3;
}

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int pow_mod(int a, int n, int mod) {
  int result = 1;
  while (n) {
    if (n & 1) {
      result = (u64)result * a % mod;
    }
    a = (u64)a * a % mod;
    n >>= 1;
  }
  return result;
}

int main() {
  registerValidation();
  int sum_n = 0;
  while (!inf.eof()) {
    int n = inf.readInt(1, 200'000);
    ensure(check(n));
    inf.readSpace();
    int p = inf.readInt(2, 1'000'000'000);
    ensure(is_prime(p));
    ensure((p - 1) % n == 0);
    inf.readSpace();
    int w = inf.readInt(0, p - 1);
    ensure(pow_mod(w, n, p) == 1);
    inf.readEoln();
    for (int i = 0; i < n; ++i) {
      inf.readInt(0, p - 1);
      if (i + 1 < n) {
        inf.readSpace();
      } else {
        inf.readEoln();
      }
    }
    ensure((sum_n += n) <= 500'000);
  }
  inf.readEof();
}
