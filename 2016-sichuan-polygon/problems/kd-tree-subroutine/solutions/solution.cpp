#include <algorithm>
#include <cstdio>

int sqr(int x)
{
    return x * x;
}

int main()
{
    const int k = 3;
    int p[k];
    int l[k];
    int h[k];
    for (int i = 0; i < k; ++ i) {
        scanf("%d", p + i);
    }
    for (int i = 0; i < k; ++ i) {
        scanf("%d", l + i);
    }
    for (int i = 0; i < k; ++ i) {
        scanf("%d", h + i);
    }
    int result = 0;
    for (int i = 0; i < k; ++ i) {
        if (p[i] < l[i] || h[i] < p[i]) {
            result += std::min(sqr(l[i] - p[i]), sqr(h[i] - p[i]));
        }
    }
    printf("%d\n", result);
}
