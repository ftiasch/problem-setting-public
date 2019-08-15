from fractions import Fraction

while True:
    try:
        n = int(input())
    except EOFError:
        break
    lst = []
    for i in range(n):
        a, b, c = map(int, input().split())
        lst.append((Fraction(a + b, a + b + c), i + 1))
    lst.sort()
    print(' '.join([str(lst[i][1]) for i in range(n)]))
