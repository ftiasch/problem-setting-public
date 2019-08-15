read = lambda: map(int, raw_input().split())
p = read()
l = read()
r = read()
n, result = len(p), 0
sqr = lambda x: x * x
for i in xrange(n):
    if p[i] < l[i] or r[i] < p[i]:
        result += min(sqr(p[i] - l[i]), sqr(p[i] - r[i]))
print(result)
