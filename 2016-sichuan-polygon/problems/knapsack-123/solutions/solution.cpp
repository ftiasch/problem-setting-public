#include <iostream>

typedef long long Long;

Long solve(Long a, Long b, Long c)
{
    if (a >= 2) {
        return a + 2 * b + 3 * c;
    }
    if (a == 1) {
        if (b >= 1) {
            return a + 2 * b + 3 * c;
        }
        if (b == 0) {
            return 1 + 2 * c;
        }
    }
    if (b == 0) {
        return c;
    }
    if (b == 1) {
        return 1 + 2 * c;
    }
    if (c == 0) {
        return b;
    }
    return 2 * b + 3 * c - 2;
}

int main()
{
    Long c1, c2, c3;
    std::cin >> c1 >> c2 >> c3;
    std::cout << solve(c1, c2, c3) << std::endl;
    return 0;
}
