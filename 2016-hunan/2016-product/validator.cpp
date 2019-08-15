#include "testlib.h"

int main()
{
    registerValidation();
    inf.readInt(1, static_cast<int>(1e9));
    inf.readSpace();
    inf.readInt(1, static_cast<int>(1e9));
    inf.readEoln();
    inf.readEof();
}
