# from __future__ import print_function

MOD = 10 ** 9 + 7

def asum(a, b):
  return (a + b) * (b - a + 1) // 2

def solve(a, x1, x2):
  if a <= x1:
    return 0
  result = 0
  if a >= x2:
    result += (x2 - x1) * (a - x2 + 1)
  result += asum(1, min(a, x2 - 1) - x1)
  return result

while True:
  try:
    a, b = list(map(int, input().split()))
    x1, x2, y1, y2 = list(map(int, input().split()))
    print((a * b * (x2 - x1) * (y2 - y1) + asum(1, a) * asum(1, b) - solve(a, x1, x2) * solve(b, y1, y2)) % MOD)
  except EOFError:
    break
