def solve(n, k):
    a = 10 ** 18
    if n - k < k:
        k = n - k
    # n - k >= k <=> k <= n/2
    result = 1
    for i in range(k):
        result = result * (n - i) // (i + 1)
        if result > a:
            return a
    return result

while True:
    try:
        n, k = list(map(int, input().split()))
    except EOFError:
        break
    print(solve(n, k))
