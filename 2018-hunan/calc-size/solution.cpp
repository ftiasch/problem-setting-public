#include <bits/stdc++.h>

int main()
{
    int h, c;
    while (scanf("%d%d", &h, &c) == 2) {
        printf("%d\n", h + std::max(c - h + 1, 0));
    }
}
