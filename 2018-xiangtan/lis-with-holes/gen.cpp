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
    for (int n = 1; n <= std::atoi(argv[1]); ++ n) {
        dfs(n, 0);
    }
    shuffle(sequences.begin(), sequences.end());
    for (auto& s : sequences) {
        int n = s.size();
        printf("%d\n", n);
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", s[i], " \n"[i == n - 1]);
        }
    }
    int count = std::atoi(argv[2]);
    int n = std::atoi(argv[3]);
    while (count --) {
        printf("%d\n", n);
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", rnd.next(0, n), " \n"[i == n - 1]);
        }
    }
}
