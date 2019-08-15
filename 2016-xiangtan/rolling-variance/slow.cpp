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
        for (int i = 0; i <= n - m; ++ i) {
            double avg = 0.;
            for (int j = 0; j < m; ++ j) {
                avg += a.at(i + j);
            }
            avg /= m;
            double var = 0.;
            for (int j = 0; j < m; ++ j) {
                var += sqr(a.at(i + j) - avg);
            }
            var /= m - 1;
            printf("%.8f\n", sqrt(var));
        }
    }
}
