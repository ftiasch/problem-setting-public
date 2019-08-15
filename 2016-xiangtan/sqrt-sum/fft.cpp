#include <algorithm>
#include <cmath>
#include <cstdio>
#include <complex>
#include <iostream>
#include <vector>

typedef std::complex<double> Complex;

const double pi = acos(-1.);

void FFT(Complex P[], int n, int oper)
{
    for (int i = 1, j = 0; i < n - 1; i++) {
        for (int s = n; j ^= s >>= 1, ~j & s;);
        if (i < j) {
            swap(P[i], P[j]);
        }
    }
    for (int d = 0; (1 <<d) <n; d++) {
        int m = 1 << d, m2 = m * 2;
        double p0 = pi / m * oper;
        Complex unit_p0(cos(p0), sin(p0));
        for (int i = 0; i <n; i += m2) {
            Complex unit = 1;
            for (int j = 0; j <m; j++) {
                Complex &P1 = P[i + j + m], &P2 = P[i + j];
                Complex t = unit * P1;
                P1 = P2 - t;
                P2 = P2 + t;
                unit = unit * unit_p0;
            }
        }
    }
}

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; ++ i) {
            scanf("%d", &b[i]);
        }
        int M = std::max(*std::max_element(a.begin(), a.end()), *std::max_element(b.begin(), b.end()));
        std::vector<int> s(M + 1);
        for (int i = 0, j = 0; i <= M; ++ i) {
            if ((j + 1) * (j + 1) <= i) {
                j ++;
            }
            s[i] = j;
        }
        int min_a = *std::min_element(a.begin(), a.end());
        int max_a = *std::max_element(a.begin(), a.end());
        int min_b = *std::min_element(b.begin(), b.end());
        int max_b = *std::max_element(b.begin(), b.end());
        M = 1;
        while (M <= (max_a - min_a) + (max_b - min_b)) {
            M <<= 1;
        }
        std::vector<Complex> A(M), B(M);
        for (int i = 0; i < n; ++ i) {
            A[a[i] - min_a] += 1;
        }
        for (int i = 0; i < m; ++ i) {
            B[max_b - b[i]] += 1;
        }
        FFT(A.data(), M, 1);
        FFT(B.data(), M, 1);
        for (int i = 0; i < M; ++ i) {
            A[i] *= B[i];
        }
        FFT(A.data(), M, -1);
        long long result = 0;
        for (int i = 0, d = 0; i < M; ++ i) {
            long long w = A[i].real() / M + .5;
            if (w) {
                result += s.at(std::abs(i + min_a - max_b)) * w;
            }
        }
        std::cout << result << std::endl;
    }
}
