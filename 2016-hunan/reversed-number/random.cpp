#include "testlib.h"

#include <algorithm>
#include <numeric>
#include <vector>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = std::atoi(argv[1]);
    printf("%d\n", n);
    printf("%s\n", rnd.next(format("[0-9]{%d}", n)).c_str());
}
