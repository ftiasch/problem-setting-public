#include <cstdio>

const int N = 200001;

int a[N];

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i <= n; ++ i) {
            scanf("%d", a + i);
        }
        int h = n + 1;
        long long cnt = 0;
        while (cnt < h) {
            cnt += a[-- h];
        }
        printf("%d\n", h);
    }

}
