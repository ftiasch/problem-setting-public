#include "testlib.h"

#include <string>
#include <iostream>

int main()
{
    registerValidation();
    int n = inf.readInt(1, (int)1e5);
    inf.readSpace();
    int q = inf.readInt(1, (int)1e5);
    inf.readEoln();
    auto s = inf.readToken();
    int sum = 0;
    for (auto&& c : s) {
        if (c == '(') {
            sum ++;
        } else if (c == ')') {
            sum --;
            ensure(sum >= 0);
        } else {
            ensure(false);
        }
    }
    inf.readEoln();
    ensure(!sum);
    while (q --) {
        int a = inf.readInt(1, n);
        inf.readSpace();
        int b = inf.readInt(1, n);
        inf.readEoln();
        ensure(a != b);
    }
    inf.readEof();
}
