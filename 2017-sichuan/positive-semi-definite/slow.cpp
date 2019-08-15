#include <cstdio>
#include <cstring>

int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3) {
        bool found = false;
        for (int x_ = -200; x_ <= 200 && !found; ++ x_) {
            for (int y_ = -200; y_ <= 200 && !found; ++ y_) {
                double x = x_ / 10.0;
                double y = y_ / 10.0;
                found |= a * x * x + b * x * y + c * y * y + 1e-9 < 0;
            }
        }
        puts(found ? "No" : "Yes");
    }
}
