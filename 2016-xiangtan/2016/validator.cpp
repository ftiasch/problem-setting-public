#include "testlib.h"

int main()
{
    registerValidation();
    inf.readToken("[1-9][0-9]{0, 99999}");
    inf.readEoln();
    int a11, a12, a21, a22;
    a11 = inf.readInt(0, 6), inf.readSpace(), a12 = inf.readInt(0, 6), inf.readEoln();
    a21 = inf.readInt(0, 6), inf.readSpace(), a22 = inf.readInt(0, 6), inf.readEoln();
    ensure((a11 * a22 - a12 * a21) % 7);
    inf.readEof();
}
