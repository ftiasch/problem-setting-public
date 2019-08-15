#include <bits/stdc++.h>

#include "testlib.h"

std::vector<int> v;

void dfs(int n, int i)
{
    if (i <= n) {
        v.push_back(0);
        for (int j = 0; j <= n; ++ j) {
            v.back() = j;
            dfs(n, i + 1);
        }
        v.pop_back();
    } else {
        printf("%d\n", n);
        for (int i = 0; i <= n; ++ i) {
            printf("%d%c", v[i], " \n"[i == n]);
        }
    }
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    dfs(std::atoi(argv[1]), 0);
}
