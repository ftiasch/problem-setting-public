#include <cstdio>

bool check(int a, int b, int c)
{
    if (a < 0) {
        return false;
    }
    if (a == 0) {
        if (b != 0) {
            return false;
        }
        return c >= 0;
    }
    return b * b - 4 * a * c <= 0;
}

int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3) {
        puts(check(a, b, c) ? "Yes" : "No");
    }
}
