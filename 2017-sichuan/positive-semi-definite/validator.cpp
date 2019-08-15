#include "testlib.h"

int main()
{
    registerValidation();
    int test_count = 0;
    auto MIN = -10;
    auto MAX = 10;
    while (!inf.eof()) {
        test_count ++;
        inf.readInt(MIN, MAX);
        inf.readSpace();
        inf.readInt(MIN, MAX);
        inf.readSpace();
        inf.readInt(MIN, MAX);
        inf.readEoln();
    }
    ensure(1 <= test_count && test_count <= 10000);
    inf.readEof();
}
