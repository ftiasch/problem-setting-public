#include "testlib.h"

int main()
{
    registerValidation();
    inf.readInt(1, 100000);
    inf.readSpace();
    inf.readInt(1, 100000);
    inf.readSpace();
    inf.readInt(1, 100000);
    inf.readEoln();
    inf.readEof();
}
