#include <bits/stdc++.h>

static const int K = 32;
static const long long LIMIT = 1e18;

static int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(int argc, char *argv[]) {
  int T = std::atoi(argv[1]);
  std::vector<std::pair<int, int>> inputs;
  for (int k = 3; k < K; ++k) {
    uint64_t result = 1;
    int n = k + k;
    for (int i = 0; i < k; ++i) {
      result = result * (n - i) / (i + 1);
    }
    while (result <= LIMIT) {
      inputs.emplace_back(n, k);
      n++;
      int g = gcd(n - k, n);
      result = result / ((n - k) / g) * (n / g);
    }
    inputs.emplace_back(n, k);
  }
  for (int i = static_cast<int>(inputs.size()) - 1; i >= 0 && T--; --i) {
    printf("%d %d\n", inputs[i].first, inputs[i].second);
  }
}
