#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

std::vector<long long> gen(const std::vector<long long>& a)
{
    std::vector<long long> result;
    int n = a.size();
    for (int mask = 0; mask < 1 << n; ++ mask) {
        long long sum = 0;
        for (int i = 0; i < n; ++ i) {
            if (mask >> i & 1) {
                sum ^= a.at(i);
            }
        }
        result.push_back(sum);
    }
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%lld", &a.at(i));
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%lld", &b.at(i));
        }
        a = gen(a);
        b = gen(b);
        long long result = 0;
        int p = 0;
        for (auto& x : a) {
            while (p < static_cast<int>(b.size()) && b.at(p) < x) {
                p ++;
            }
            result += p < static_cast<int>(b.size()) && b.at(p) == x;
        }
        std::cout << result << std::endl;
    }
}
