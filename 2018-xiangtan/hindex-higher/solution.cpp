#include <algorithm>
#include <cstdio>

int solve(int n, int a)
{
    return (n + a) / 2;
}

int main()
{
    int n, a;
    while (scanf("%d%d", &n, &a) == 2) {
        printf("%d\n", solve(n, a));
    }
}
