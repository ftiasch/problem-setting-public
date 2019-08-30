#include "gen.h"

struct Generator : public GeneratorBase {
  Generator(int m) : GeneratorBase(m + 1, m) {
    for (int i = 0; i < m + 1; ++i) {
      for (int j = 0; j < m; ++j) {
        out[i][j] = i == j + 1 ? 2 : 1;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  ensure(argc >= 2);
  int n = std::atoi(argv[1]);
  Generator g(n);
  g.shuffle_columns();
  g.print();
}
