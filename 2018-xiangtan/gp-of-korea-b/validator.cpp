#include "testlib.h"

int main()
{
    registerValidation();
    int tests = 0;
    while (!inf.eof()) {
        inf.readInt(1, 5000);
        inf.readSpace();
        inf.readInt(1, 5000);
        inf.readEoln();
        tests ++;
    }
    fprintf(stderr, "# = %d\n", tests);
    ensure(tests <= 5000);
    inf.readEof();
}
