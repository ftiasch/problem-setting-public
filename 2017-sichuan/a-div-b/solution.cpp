#include <cstdio>
#include <limits>
#include <iostream>

int signum(long long x)
{
    return x < 0 ? -1 : x > 0;
}

int main()
{
    long long a, b;
    std::ios::sync_with_stdio(false);
    while (std::cin >> a >> b) {
        if (a == std::numeric_limits<long long>::min() && b == -1) {
            std::cout << "9223372036854775808";
        } else if (a % b == 0) {
            std::cout << a / b;
        } else {
            long long q = a / b;
            if (signum(a) * signum(b) < 0) {
                q --;
            }
            std::cout << q;
        }
        std::cout << std::endl;
    }
}
