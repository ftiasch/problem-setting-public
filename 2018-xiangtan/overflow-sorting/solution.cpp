#include <algorithm>
#include <cstdio>

const int N = 100000;

int a[N], b[N], c[N], ord[N];

bool cmp(int i, int j)
{
    auto x = c[i] * (1ULL * a[j] + b[j] + c[j]);
    auto y = c[j] * (1ULL * a[i] + b[i] + c[i]);
    if (x == y) {
        return i < j;
    }
    return x > y;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d%d", a + i, b + i, c + i);
            ord[i] = i;
        }
        std::sort(ord, ord + n, cmp);
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", ord[i] + 1, " \n"[i == n - 1]);
        }
    }
}
