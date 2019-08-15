#include "testlib.h"

int main()
{
    registerValidation();
    int len = 0;
    while (!inf.eof()) {
        len += inf.readToken("[abc]{1,10000}").size();
        inf.readEoln();
        len += inf.readToken("[abc]{1,10000}").size();
        inf.readEoln();
    }
    fprintf(stderr, "sum len = %d\n", len);
    ensure(len <= 250000);
    inf.readEof();
}
