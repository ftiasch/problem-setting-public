#!/usr/bin/env python

from fractions import Fraction

def solve(a, b, c):
    result = 0
    result += Fraction(b, a + b + c) * Fraction(c, a + c)
    result += Fraction(c, a + b + c) * Fraction(b, a + b)
    return result

while True:
    try:
        a, b, c = map(int, raw_input().split())
    except EOFError:
        break
    print solve(a, b, c), solve(b, c, a), solve(c, a, b)
