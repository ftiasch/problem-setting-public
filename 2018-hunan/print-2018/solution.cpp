#include <bits/stdc++.h>

const char C[5][233] = {
    "ooo.ooo.ooo.ooo",
    "  o.o o. o .o o",
    "ooo.o o. o .ooo",
    "o  .o o. o .o o",
    "ooo.ooo.ooo.ooo"
};

int main()
{
    int w;
    scanf("%d", &w);
    for (int i = 0; i < 5; ++ i) {
        for (int j = 0; C[i][j]; ++ j) {
            if (C[i][j] == '.') {
                for (int k = 0; k < w; ++ k) {
                    putchar('.');
                }
            } else {
                putchar(C[i][j] == ' ' ? '.' : C[i][j]);
            }
        }
        puts("");
    }
}
