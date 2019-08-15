#include <cstdio>
#include <vector>

void update(int &x, int a)
{
    if (!~x || a < x) {
        x = a;
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> best(n, -1);
        for (int _ = 0; _ < m; ++ _) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a --;
            b --;
            if (b - a == 1) {
                update(best.at(a), c);
            }
        }
        int result = 0;
        for (int i = 0; i + 1 < n && ~result; ++ i) {
            if (~best.at(i)) {
                result += best.at(i);
            } else {
                result = -1;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
