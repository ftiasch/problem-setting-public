#include "testlib.h"

int main()
{
    registerValidation();
    int tests = 0;
    while (!inf.eof()) {
        inf.readInt(1, 1000000000);
        inf.readSpace();
        inf.readInt(0, 1000000000);
        inf.readEoln();
        tests ++;
    }
    ensure(tests <= 100000);
    inf.readEof();
}
