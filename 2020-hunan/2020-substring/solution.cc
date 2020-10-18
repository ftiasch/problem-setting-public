#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    std::vector<char> s(n + 1);
    scanf("%s", s.data());
    int result = 0;
    for (int i = 0; i + 4 <= n;) {
      if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' &&
          s[i + 3] == '0') {
        i += 4, result++;
      } else {
        i++;
      }
    }
    printf("%d\n", result);
  }
}
