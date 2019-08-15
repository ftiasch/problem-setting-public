#include <cstdio>
#include <iostream>

int main()
{
    int a, b, c, d;
    while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4) {
        int result = 0;
        for (int i = a; i <= b; ++ i) {
            for (int j = c; j <= d; ++ j) {
                if ((long long)i * j % 2017 == 0) {
                    result ++;
                }
            }
        }
        std::cout << result << std::endl;
    }
}
