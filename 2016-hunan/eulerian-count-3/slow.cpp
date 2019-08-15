#include <cstdio>
#include <vector>

const int MOD = (int)1e9 + 7;

void update(int &x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3) {
        std::vector<int> ways((a + 1) * (b + 1) * (c + 1) * 3);
        auto w = [&](int i, int j, int k, int x) -> int& {
            return ways.at(((i * (b + 1) + j) * (c + 1) + k) * 3 + x);
        };
        w(a, b, c, 0) = 1;
        for (int i = a; i >= 0; -- i) {
            for (int j = b; j >= 0; -- j) {
                for (int k = c; k >= 0; -- k) {
                    if (i) {
                        update(w(i - 1, j, k, 0), (long long)i * w(i, j, k, 1) % MOD);
                        update(w(i - 1, j, k, 1), (long long)i * w(i, j, k, 0) % MOD);
                    }
                    if (j) {
                        update(w(i, j - 1, k, 0), (long long)j * w(i, j, k, 2) % MOD);
                        update(w(i, j - 1, k, 2), (long long)j * w(i, j, k, 0) % MOD);
                    }
                    if (k) {
                        update(w(i, j, k - 1, 1), (long long)k * w(i, j, k, 2) % MOD);
                        update(w(i, j, k - 1, 2), (long long)k * w(i, j, k, 1) % MOD);
                    }
                }
            }
        }
        printf("%d\n", w(0, 0, 0, 0));
    }
    return 0;
}
