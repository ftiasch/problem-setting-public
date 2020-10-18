#include "testlib.h"

#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

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

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int T = std::atoi(argv[1]);
  const int N = std::atoi(argv[2]);
  const int P = std::atoi(argv[3]);
  int n = N;
  while (!check(n)) {
    n--;
  }
  std::vector<int> primes;
  for (int q = (P - 1) / n * n; q >= n; q -= n) {
    if (is_prime(q + 1)) {
      primes.push_back(q + 1);
    }
  }
  int p = primes[rnd.next(0, static_cast<int>(primes.size()) - 1)];
  while (T--) {
    std::vector<int> exps;
    for (int i = 1; i * i <= p - 1; ++i) {
      if ((p - 1) % i == 0) {
        exps.push_back(i);
        exps.push_back((p - 1) / i);
      }
    }
    std::sort(exps.begin(), exps.end());
    int w0 = rnd.next(1, p - 1);
    int w = 0;
    for (auto &&e : exps) {
      if (pow_mod(w0, e * n, p) == 1) {
        w = pow_mod(w0, e, p);
        break;
      }
    }
    printf("%d %d %d\n", n, p, w);
    for (int i = 0; i < n; ++i) {
      printf("%d%c", rnd.next(0, p - 1), " \n"[i + 1 == n]);
    }
  }
}
