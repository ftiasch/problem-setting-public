#include <cstdio>

const int N = 1e5 + 10;

char s[N];

int main() {
  int n;
  while (scanf("%d%s", &n, s) == 2) {
    int ret = 0;
    for (int i = 0; i + 4 <= n;) {
      if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '0')
        i += 4, ++ret;
      else
        ++i;
    }
    printf("%d\n", ret);
  }
  return 0;
}
