#include "testlib.h"

#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int count = std::atoi(argv[1]);
    int max = std::atoi(argv[2]);
    int w = std::atoi(argv[3]);
    while (count --) {
        int n = rnd.wnext(1, max, w);
        int m = rnd.wnext(1, max, w);
        printf("%d %d\n", n, m);
    }
}
