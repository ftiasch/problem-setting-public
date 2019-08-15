#include <bits/stdc++.h>

#include "testlib.h"

void gen(std::vector<std::string>& ss, int n, std::string s)
{
    if (!s.empty()) {
        ss.push_back(s);
    }
    if (n) {
        gen(ss, n - 1, s + 'a');
        gen(ss, n - 1, s + 'b');
        gen(ss, n - 1, s + 'c');
    }
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    std::vector<std::string> ss;
    gen(ss, n, "");
    for (auto&& s : ss) {
        for (auto&& t : ss) {
            printf("%s\n%s\n", s.c_str(), t.c_str());
        }
    }
    int count = std::atoi(argv[2]);
    int len = std::atoi(argv[3]);
    while (count --) {
        for (int _ = 0; _ < 2; ++ _) {
            for (int i = 0; i < len; ++ i) {
                putchar("ab"[rnd.next(0, 1)]);
            }
            puts("");
        }
    }
}
