for n in range(1, 7):
    for msk in range(2 ** (n * (n - 1) // 2)):
        print(n, bin(msk).count('1'))
        cnt = 0
        for i in range(n):
            for j in range(i):
                if msk >> cnt & 1:
                    print(i + 1, j + 1, 1)
                cnt += 1
