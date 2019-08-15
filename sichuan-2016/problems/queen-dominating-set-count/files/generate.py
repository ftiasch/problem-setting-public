from collections import defaultdict
from fractions import Fraction

def binom(n, k):
    if n < k:
        return 0
    result = 1
    for i in xrange(k):
        result *= n - i
        result /= 1 + i
    return result

def answer(n, m, k):
    result = 0
    for i in xrange(n):
        for j in xrange(m):
            count = n * m
            for x in xrange(n):
                for y in xrange(m):
                    if i == x or j == y or i + j == x + y or i - j == x - y:
                        count -= 1
            result += binom(n * m, k) - binom(count, k)
    return result

def eliminate(matrix):
    n, m = len(matrix), len(matrix[0]) - 1
    for r in xrange(m):
        i = r
        while matrix[i][r] == 0:
            i += 1
        matrix[r], matrix[i] = matrix[i], matrix[r]
        s = Fraction(matrix[r][r])
        for j in xrange(m + 1):
            matrix[r][j] /= s
        for i in xrange(n):
            if i != r and matrix[i][r] != 0:
                s = matrix[i][r]
                for j in xrange(m + 1):
                    matrix[i][j] -= matrix[r][j] * s
    for i in xrange(m, n):
        assert matrix[i][m] == 0
    return [matrix[i][m] for i in xrange(m)]

def pack(parts):
    return "{%s}" %(', '.join(parts))

def get_category(n, m):
    assert n <= m
    if 2 * n < m:
        return n % 2
    if (n + m) % 2 == 1:
        return 2
    return 3 + n % 2

result = []
for k in xrange(1, 9):
    d = k + 3
    values = defaultdict(list)
    s, done = 2, 0
    while done < 5:
        for n in xrange(1, s / 2):
            m = s - n
            category = get_category(n, m)
            c = []
            for i in xrange(d):
                for j in xrange(d):
                    c.append(pow(n, i) * pow(m, j))
            c.append(answer(n, m, k))
            values[category].append(c)
            if len(values[category]) == d * d:
                done += 1
        s += 1
    for category, coefficient in sorted(values.items()):
        coefficient = eliminate(coefficient)
        parts = []
        for i in xrange(d):
            for j in xrange(d):
                c = coefficient[i * d + j]
                if c != 0:
                    parts.append(pack(map(str, (c.numerator, c.denominator, i, j))))
        result.append(pack(parts))
print(pack(result))
