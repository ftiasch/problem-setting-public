#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  while (std::cin >> n) {
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> s[i];
    }
    long long result = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (s[i] + s[j] == s[j] + s[i]) {
          result++;
        }
      }
    }
    std::cout << result << std::endl;
  }
}
