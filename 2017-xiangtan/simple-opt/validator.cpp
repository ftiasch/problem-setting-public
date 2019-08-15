#include "testlib.h"

int main()
{
    registerValidation();
    int test_count = 0;
    while (!inf.eof()) {
        test_count ++;
        inf.readInt(1, 1000000000);
        inf.readSpace();
        inf.readInt(1, 1000000000);
        inf.readEoln();
    }
    ensure(1 <= test_count && test_count <= 10000);
    inf.readEof();
}
