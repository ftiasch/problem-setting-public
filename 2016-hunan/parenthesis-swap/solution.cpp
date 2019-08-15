#include <algorithm>
#include <cstdio>
#include <vector>

bool check(const std::vector<char>& s, const std::vector<int>& first, int a, int b)
{
    if (s.at(a) == s.at(b)) {
        return true;
    }
    if (a > b) {
        std::swap(a, b);
    }
    if (s.at(a) == ')') {
        return true;
    }
    return first.at(a) > b;
}

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        std::vector<char> s(n + 1);
        scanf("%s", s.data());
        std::vector<int> sum(n + 1);
        for (int i = 0; i < n; ++ i) {
            int& ref = sum.at(i + 1);
            ref= sum.at(i);
            if (s.at(i) == '(') {
                ref ++;
            } else {
                ref --;
            }
        }
        std::vector<int> first(n);
        first.at(n - 1) = n;
        for (int i = n - 2; i >= 0; -- i) {
            first.at(i) = first.at(i + 1);
            if (sum.at(i + 1) < 2) {
                first.at(i) = i + 1;
            }
        }
        while (q --) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            puts(check(s, first, a, b) ? "Yes" : "No");
        }
    }
}
