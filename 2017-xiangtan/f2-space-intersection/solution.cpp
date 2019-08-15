#include <cassert>
#include <iostream>
#include <vector>

using Long = long long;

const int B = 60;

int eliminate(std::vector<Long>& a) // -> rank
{
    int r = 0;
    int n = a.size();
    for (int j = 0; j < B; ++ j) {
        int p = r;
        while (p < n && (~a.at(p) >> j & 1)) {
            p ++;
        }
        if (p < n) {
            std::swap(a.at(r), a.at(p));
            for (int i = 0; i < n; ++ i) {
                if (i != r && (a.at(i) >> j & 1)) {
                    a.at(i) ^= a.at(r);
                }
            }
            r ++;
        }
    }
    a.resize(r);
    return r;
}

std::vector<Long> construct_nspace(std::vector<Long>& a)
{
    int r = eliminate(a);
    Long mask = (1LL << B) - 1;
    std::vector<int> pivot(r);
    for (int i = 0; i < r; ++ i) {
        int& p = pivot.at(i);
        while (~a.at(i) >> p & 1) {
            p ++;
        }
        mask ^= 1LL << p;
    }
    std::vector<Long> comp;
    for (int j = 0; j < B; ++ j) {
        if (mask >> j & 1) {
            comp.push_back(1LL << j);
            for (int i = 0; i < r; ++ i) {
                if (a.at(i) >> j & 1) {
                    comp.back() ^= 1LL << pivot.at(i);
                }
            }
        }
    }
    return comp;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while (std::cin >> n) {
        std::vector<Long> a(n), b(n);
        for (int i = 0; i < n; ++ i) {
            std::cin >> a.at(i);
        }
        for (int i = 0; i < n; ++ i) {
            std::cin >> b.at(i);
        }
        auto c = construct_nspace(a);
        for (auto&& x : construct_nspace(b)) {
            c.push_back(x);
        }
        std::cout << (1LL << B - eliminate(c)) << std::endl;
    }
}
