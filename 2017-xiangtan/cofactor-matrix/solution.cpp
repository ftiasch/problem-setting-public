#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <vector>

const int MOD = (int)1e9 + 7;

int inv(int a)
{
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inv(MOD % a) % MOD;
}

int inv_mat(int n, std::vector<std::vector<int>>& a) // -> det
{
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            a.at(i).push_back(i == j);
        }
    }
    long long det = 1;
    for (int j = 0; j < n; ++ j) {
        int pivot = j;
        while (pivot < n && a.at(pivot).at(j) == 0) {
            pivot ++;
        }
        if (pivot == n) {
            return 0;
        }
        if (j != pivot) {
            det = det * (MOD - 1LL) % MOD;
            std::swap(a.at(j), a.at(pivot));
        }
        det = det * a.at(j).at(j) % MOD;
        long long inv_ = inv(a.at(j).at(j));
        for (int k = 0; k < n + n; ++ k) {
            a.at(j).at(k) = a.at(j).at(k) * inv_ % MOD;
        }
        for (int i = 0; i < n; ++ i) {
            if (i != j && a.at(i).at(j)) {
                long long t = a.at(i).at(j);
                for (int k = 0; k < n + n; ++ k) {
                    a.at(i).at(k) += MOD - t * a.at(j).at(k) % MOD;
                    if (a.at(i).at(k) >= MOD) {
                        a.at(i).at(k) -= MOD;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            std::swap(a.at(i).at(j), a.at(i).at(j + n));
        }
        a.at(i).resize(n);
    }
    return det;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        for (int i = 1; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                scanf("%d", &a.at(i).at(j));
            }
        }
        auto inv_a = a;
        for (int j = 0; j < n; ++ j) {
            inv_a.at(0).at(j) = rand() % MOD;
        }
        int det = inv_mat(n, inv_a);
        for (int i = 0; i < n; ++ i) {
            int result = (long long)det * inv_a.at(i).at(0) % MOD;
            if ((i & 1) && result) {
                result = MOD - result;
            }
            printf("%d%c", result, " \n"[i == n - 1]);
        }
    }
}
