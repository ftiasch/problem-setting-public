def read():
    return tuple([
        (parts.count('a') % 2, parts.count('b') % 2)
        for parts in input().split('c')
    ])

try:
    while True:
        a = read()
        b = read()
        print("Yes" if a == b else "No")
except EOFError:
    pass
