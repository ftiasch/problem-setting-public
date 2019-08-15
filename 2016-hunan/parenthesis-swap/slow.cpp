#include <cstdio>
#include <vector>

int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        std::vector<char> s(n + 1);
        scanf("%s", s.data());
        while (q --) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            std::swap(s.at(a), s.at(b));
            int sum = 0;
            bool valid = true;
            for (auto&& c : s) {
                if (c == '(') {
                    sum ++;
                } else if (c == ')') {
                    sum --;
                    valid &= sum >= 0;
                }
            }
            valid &= !sum;
            puts(valid ? "Yes" : "No");
            std::swap(s.at(a), s.at(b));
        }
    }
}
