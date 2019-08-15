#include "testlib.h"

#include <bits/stdc++.h>

std::vector<int> cur;
std::vector<std::vector<int>> sequences;

void dfs(int n, int i)
{
    if (i == n) {
        sequences.push_back(cur);
    } else {
        cur.push_back(0);
        for (int j = 0; j <= n; ++ j) {
            cur[i] = j;
            dfs(n, i + 1);
        }
        cur.pop_back();
    }
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    int a1 = std::atoi(argv[2]);
    int b1 = std::atoi(argv[3]);
    int a2 = std::atoi(argv[4]);
    int b2 = std::atoi(argv[5]);
    printf("%d\n", n);
    for (int i = 0; i < n; ++ i) {
        printf("%d %d %d\n", rnd.next(a1, b1), rnd.next(a1, b1), rnd.next(a2, b2));
    }
}
