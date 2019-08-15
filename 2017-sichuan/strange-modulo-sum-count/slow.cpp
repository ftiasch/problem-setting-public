#include <cstdio>
#include <vector>

const int MOD = (int)1e9 + 7;
const long long BND = 2017;
// const long long BND = (long long)1e10 + 19;

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
        std::vector<int> ways(BND);
        ways[0] = 1;
        for (int i = 0; i < n; ++ i) {
            int a;
            scanf("%d", &a);
            std::vector<int> new_ways(BND);
            for (int j = 0; j < BND; ++ j) {
                for (int k = 0; k < BND - a; ++ k) {
                    update(new_ways[(j + k) % BND], ways[j]);
                }
            }
            ways.swap(new_ways);
        }
        printf("%d\n", ways[0]);
    }
}
