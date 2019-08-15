#include "testlib.h"

int main()
{
    registerValidation();
    int test_count = 0;
    auto MIN = std::numeric_limits<long long>::min();
    auto MAX = std::numeric_limits<long long>::max();
    while (!inf.eof()) {
        test_count ++;
        inf.readLong(MIN, MAX);
        inf.readSpace();
        inf.readLong(MIN, MAX);
        inf.readEoln();
    }
    ensure(1 <= test_count && test_count <= 10000);
    inf.readEof();
}
