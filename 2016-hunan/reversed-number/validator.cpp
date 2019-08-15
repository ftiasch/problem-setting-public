#include "testlib.h"

int main()
{
    registerValidation();
    int n = inf.readInt(1, (int)1e5);
    inf.readEoln();
    inf.readToken(format("[0-9]{%d}", n));
    inf.readEoln();
    inf.readEof();
}
