from sys import stdin

input = stdin.readline

def tournament():
    n, kim, lim = map(int, input().split())
    round = 0

    while True:
        if lim == kim:
            return round
        else:
            round += 1
            lim = (lim - 1) // 2 + 1
            kim = (kim - 1) // 2 + 1

print(tournament())