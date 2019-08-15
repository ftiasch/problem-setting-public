#include <algorithm>
#include <iostream>

int main()
{
    long long a, b, c;
    std::cin >> a >> b >> c;
    long long result = 0;
    for (long long n = a + 2 * b + 3 * c; n; -- n) {
        bool found = false;
        for (long long k = std::min(c, n / 3); !found && k >= 0; -- k) {
            auto j = std::min(b, (n - 3 * k) / 2);
            found |= n - 3 * k - 2 * j <= a;
        }
        result += found;
    }
    std::cout << result << std::endl;
    return 0;
}
