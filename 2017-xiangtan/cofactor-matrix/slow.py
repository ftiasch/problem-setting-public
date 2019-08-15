#!/usr/bin/env sage-python
from sage.all_cmdline import *

F = GF(10 ** 9 + 7)

input = sys.stdin

count = 0
while True:
    try:
        n = int(input.readline())
    except:
        break
    a = [map(int, input.readline().rstrip().split()) for _ in range(n - 1)]
    print(' '.join([
        str(det(matrix([
            [F(a[i][j] if j < k else a[i][j + 1]) for j in range(n - 1)]
            for i in range(n - 1)
        ])))
        for k in range(n)
    ]))
    count += 1
    sys.stderr.write("{}\n".format(count))
