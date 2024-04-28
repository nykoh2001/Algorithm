from sys import stdin

input = stdin.readline

def tiling():
    n = int(input())
    tiles = [0 for _ in range(n + 1)]
    if n == 1:
        return 1
    tiles[1] = 1
    tiles[2] = 2
    for i in range(3, n + 1):
        tiles[i] = (tiles[i - 1] + tiles[i - 2]) % 10007
    return tiles[n]

print(tiling())