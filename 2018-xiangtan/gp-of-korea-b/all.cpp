#include "testlib.h"

#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int max = std::atoi(argv[1]);
    for (int i = 1; i <= max; ++ i) {
        for (int j = 1; j <= max; ++ j) {
            printf("%d %d\n", i, j);
        }
    }
}
