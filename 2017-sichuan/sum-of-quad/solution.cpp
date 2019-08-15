#include <cstdio>
#include <vector>

const int MOD = (int)1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        std::vector<int> dp = a;
        for (int _ = 0; _ < 4; ++ _) {
            int s = 0;
            for (int i = 0; i < n; ++ i) {
                int tmp = dp.at(i);
                dp.at(i) = (long long)s * a.at(i) % MOD;
                update(s, tmp);
            }
            if (_ == 3) {
                printf("%d\n", s);
            }
        }
    }
}
