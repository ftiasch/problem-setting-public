#!/usr/bin/env sage-python
from sage.all_cmdline import *

F = GF(10 ** 9 + 7)

input = sys.stdin

def cofactor(a, x, y):
    n = len(a)
    return det(matrix([
        [ F(a[i][j]) for j in range(n) if j != y ]
        for i in range(n) if i != x
    ]))


while True:
    try:
        n = int(input.readline())
    except:
        break
    a = [map(int, input.readline().rstrip().split()) for _ in range(n)]
    for i in range(n):
        print(' '.join(map(str, [cofactor(a, i, j) for j in range(n)])))
