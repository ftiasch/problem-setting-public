#include <algorithm>
#include <cstdio>
#include <cstring>

double solve(int* x, int* y)
{
    if (x[0] > x[1]) {
        for (int i = 0; i < 4; ++ i) {
            x[i] *= -1;
        }
        std::swap(x[2], x[3]);
    }
    if (y[0] > y[1]) {
        for (int i = 0; i < 4; ++ i) {
            y[i] *= -1;
        }
        std::swap(y[2], y[3]);
    }
    int x_[2], y_[2];
    x_[0] = std::max(x[0], x[2]);
    x_[1] = std::min(x[1], x[3]);
    y_[0] = std::max(y[0], y[2]);
    y_[1] = std::min(y[1], y[3]);
    if (x_[0] >= x_[1] || y_[0] >= y_[1]) {
        return 0.;
    }
    double k = static_cast<double>((y[1] - y[0])) / (x[0] - x[1]);
    double b = y[1] - k * x[0];
    double result = 0.;
    for (int msk = 0; msk < 4; ++ msk) {
        int x0 = x_[msk & 1];
        int y0 = y_[msk >> 1];
        double p = k * x0 + b - y0;
        double q = (y0 - b) / k - x0;
        if (p >= 0 && q >= 0) {
            result += (__builtin_parity(msk) ? -1 : 1) * p * q;
        }
    }
    return result;
}

int main()
{
    int x[4], y[4];
    while (scanf("%d%d", x, y) == 2) {
        for (int i = 1; i < 4; ++ i) {
            scanf("%d%d", x + i, y + i);
        }
        printf("%.8f\n", .5 * solve(x, y));
    }
}
