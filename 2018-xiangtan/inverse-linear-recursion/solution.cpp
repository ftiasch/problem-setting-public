#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

namespace algo {
using i64 = int64_t;
}

namespace algo {
template <typename T> static T exp_by_sqr(T a, i64 n) {
  T res = T::one();
  while (n) {
    if (n & 1) {
      res *= a;
    }
    a *= a;
    n >>= 1;
  }
  return res;
}
} // namespace algo

namespace algo {
template <int _MOD> struct Zm {
  using Z = Zm<_MOD>;

  static int MOD;

  static int mod() { return _MOD ? _MOD : MOD; }

  static Z zero() { return Z(0); }

  static Z one() { return Z(1); }

  Zm() : n(zero()) {}

  explicit Zm(i64 _n) : n(_n % mod()) {
    if (n < 0) {
      n += mod();
    }
  }

  Zm(const Z &o) : n(o.n) {}

  operator int() const { return n; }

  Z neg() const { return Z(n ? mod() - n : 0); }

  Z inv() const {

    int t = 0;
    int newt = 1;
    int r = mod();
    int newr = n;
    while (newr) {
      int q = r / newr;
      t -= q * newt, std::swap(t, newt);
      r -= q * newr, std::swap(r, newr);
    }
    assert(r == 1);
    return Z(t < 0 ? t + mod() : t);
  }

  Z pow(i64 n) const { return exp_by_sqr(*this, n); }

  Z &operator+=(const Z &o) {
    add(n, o.n);
    return *this;
  }

  Z &operator*=(const Z &o) {
    n = static_cast<i64>(n) * o.n % mod();
    return *this;
  }

  Z operator+(const Z &o) const { return Z(*this) += o; }

  Z operator*(const Z &o) const { return Z(*this) *= o; }

  int n;

private:
  static void add(int &x, int a) {
    x += a;
    if (x >= mod()) {
      x -= mod();
    }
  }
};

template <> int Zm<0>::MOD = 0;
} // namespace algo

namespace algo {
template <typename T, int MAX_DIM> struct Matrix {
public:
  static Matrix one() {
    Matrix m;
    for (int i = 0; i < MAX_DIM; ++i) {
      m[i][i] = T::one();
    }
    return m;
  }

  Matrix() = default;

  explicit Matrix(T mat_[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < MAX_DIM; ++i) {
      for (int j = 0; j < MAX_DIM; ++j) {
        mat[i][j] = mat_[i][j];
      }
    }
  }

  T *operator[](int i) { return mat[i]; }

  const T *operator[](int i) const { return mat[i]; }

  Matrix &operator*=(const Matrix &o) {
    *this = *this * o;
    return *this;
  }

  Matrix operator*(const Matrix &o) const {
    static T result[MAX_DIM][MAX_DIM];
    for (int i = 0; i < MAX_DIM; ++i) {
      for (int j = 0; j < MAX_DIM; ++j) {
        auto &tmp = result[i][j] = T::zero();
        for (int k = 0; k < MAX_DIM; ++k) {
          tmp += mat[i][k] * o[k][j];
        }
      }
    }
    return Matrix(result);
  }

private:
  T mat[MAX_DIM][MAX_DIM];
};
} // namespace algo

using namespace algo;

const int N = 50;
const int MOD = 1000000007;

using Z = Zm<MOD>;
using M = Matrix<Z, N>;

Z a[N + 1], c[N + 1];

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 1, x; i <= n; ++i) {
      scanf("%d", &x);
      a[i] = Z(x);
    }
    M a0;
    for (int i = 0; i < n; ++i) {
      a0[0][i] = a[i + 1];
      for (int j = 1; j < i + 1; ++j) {
        a0[0][i] += a0[0][i - j] * a[j];
      }
    }
    for (int i = 1, x; i <= n; ++i) {
      scanf("%d", &x);
      c[i] = Z(x);
    }
    for (int i = n; i >= 1; --i) {
      for (int j = 1; j < i; ++j) {
        a[i] += (a[i - j] * c[j]).neg();
      }
    }
    M t;
    for (int i = 1; i < n; ++i) {
      t[i][i - 1] = Z(1);
    }
    for (int i = 1; i <= n; ++i) {
      t[n - i][n - 1] = a[i] + c[i];
    }
    printf("%d\n", static_cast<int>((a0 * exp_by_sqr(t, m - 1))[0][0]));
  }
}
