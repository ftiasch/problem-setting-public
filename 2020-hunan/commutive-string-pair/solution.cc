#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>

const int N = 1000000;

int next[N];
char s[N + 1];

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    std::unordered_map<std::string, int> count;
    for (int _ = 0; _ < n; ++_) {
      scanf("%s", s);
      int length = strlen(s);
      memset(next, -1, sizeof(*next) * length);
      for (int i = 1; i < length; ++i) {
        int j = i - 1;
        while (~j) {
          j = next[j];
          if (s[j + 1] == s[i]) {
            next[i] = j + 1;
            break;
          }
        }
      }
      int j = length - 1;
      int period = length;
      while (~j) {
        j = next[j];
        if (length % (length - (j + 1)) == 0) {
          period = length - (j + 1);
          break;
        }
      }
      s[period] = '\0';
      count[s]++;
    }
    long long result = 0;
    for (auto &&iterator : count) {
      int size = iterator.second;
      result += (size - 1LL) * size / 2;
    }
    printf("%lld\n", result);
  }
}
