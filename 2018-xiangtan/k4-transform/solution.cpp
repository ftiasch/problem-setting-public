#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> read()
{
    std::string s;
    if (!(std::cin >> s)) {
        return {};
    }
    int sum = 0;
    std::vector<int> result;
    for (size_t i = 0; i <= s.size(); ++ i) {
        if (i == s.size() || s[i] == 'c') {
            result.push_back(sum);
            sum = 0;
        } else {
            sum ^= s[i] - 'a' + 1;
        }
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    while (true) {
        auto a = read();
        if (a.empty()) {
            break;
        }
        auto b = read();
        puts(a == b ? "Yes" : "No");
    }
}
