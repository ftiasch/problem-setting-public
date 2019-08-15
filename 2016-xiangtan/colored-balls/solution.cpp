#include <algorithm>
#include <cstdio>
#include <string>

int gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

std::string solve(int a, int b, int c)
{
    int n = a + b + c;
    int q1 = n * (n - b);
    int q2 = n * (n - c);
    long long p = (long long)b * c * (q1 + q2);
    long long q = (long long)q1 * q2;
    long long g = gcd(p, q);
    return std::string("") + std::to_string(p / g) + "/" + std::to_string(q / g);
}

int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3) {
        printf("%s %s %s\n", solve(a, b, c).c_str(), solve(b, c, a).c_str(), solve(c, a, b).c_str());
    }
    return 0;
}
