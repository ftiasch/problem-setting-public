#include <algorithm>
#include <iostream>

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    while (std::cin >> n >> m) {
        long long a = gcd(n, m);
        long long b = 2LL * n * m;
        long long g = gcd(a, b);
        a /= g;
        b /= g;
        std::cout << a << "/" << b << std::endl;
    }
}
