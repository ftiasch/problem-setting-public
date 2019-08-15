#include <iostream>
#include <string>
#include <vector>

int kmp(const std::string& s, const std::string& t)
{
    int n = s.length();
    std::vector<int> next(n + 1);
    next[0] = -1;
    for (int i = 1; i < n; ++ i) {
        int p = i;
        while (p) {
            p = next[p];
            if (s[p] == s[i]) {
                next[i + 1] = p + 1;
                break;
            }
        }
    }
    int result = 0;
    int p = 0;
    for (auto&& c : t) {
        while (~p) {
            if (p < n && s[p] == c) {
                break;
            }
            p = next[p];
        }
        p ++;
        result += p == n;
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n, q;
    while (std::cin >> n >> q) {
        std::string s;
        std::cin >> s;
        while (q --) {
            int index;
            std::string p;
            std::cin >> index >> p;
            if (index --) {
                s.at(index) = p[0];
            } else {
                std::cout << kmp(p, s) << std::endl;
            }
        }
    }
    return 0;
}
