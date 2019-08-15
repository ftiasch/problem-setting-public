#include <cmath>
#include <cstdio>
#include <vector>

double sqr(double x)
{
    return x * x;
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a.at(i));
        }
        double sum = 0.;
        double sum2 = 0.;
        for (int i = 0; i < n; ++ i) {
            sum += a[i];
            sum2 += sqr(a[i]);
            if (i >= m - 1) {
                printf("%.8f\n", sqrt((sum2 - sqr(sum) / m) / (m - 1)));
                sum -= a[i - m + 1];
                sum2 -= sqr(a[i - m + 1]);
            }
        }
    }
}
