#include <testlib.h>

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 2);
  int N = std::atoi(argv[1]);
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      printf("%d %d\n", i, j);
    }
  }
}
