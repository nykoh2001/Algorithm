from sys import stdin

input = stdin.readline

def pill():
    pills = [[0 for _ in range(31)] for _ in range(31)]

    for i in range(31):
        for j in range(i):
            if i == 0:
                pills[i][j] = 0
            elif j == 0:
                pills[i][j] = 1
            else:
                pills[i][j] = pills[i - 1][j] + pills[i][j - 1]
        pills[i][i] = pills[i][i-1]

    while True:
        n = int(input())
        if n == 0:
            return
        print(pills[n][n])

pill()