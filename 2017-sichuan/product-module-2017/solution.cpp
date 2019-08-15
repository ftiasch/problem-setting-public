#include <cstdio>
#include <iostream>

int count(int a, int b)
{
    return (b - a + 1) - (b / 2017) + ((a - 1) / 2017);
}

int main()
{
    int a, b, c, d;
    while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4) {
        long long result = (b - a + 1LL) * (d - c + 1);
        std::cout << result - (long long)count(a, b) * count(c, d) << std::endl;
    }
}
