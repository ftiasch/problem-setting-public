#include "testlib.h"

#include <bits/stdc++.h>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    for (int n = 1; n <= std::atoi(argv[1]); ++ n) {
        for (int m = 0; m < 1 << n; ++ m) {
            printf("%d ", n);
            int i = n - 1;
            while (i >= 1 && (~m >> i & 1)) {
                i --;
            }
            for (; i >= 0; -- i) {
                printf("%d", m >> i & 1);
            }
            puts("");
        }
    }
    for (int i = 2; i + 1 < argc; i += 2) {
        int count = std::atoi(argv[i]);
        int n = std::atoi(argv[i + 1]);
        while (count --) {
            printf("%d ", n);
            bool output = false;
            for (int i = 2; i <= n; ++ i) {
                int a = rnd.next(0, 1);
                if (a || i == n) {
                    output = true;
                }
                if (output) {
                    printf("%d", a);
                }
            }
            puts("");
        }
    }
}
