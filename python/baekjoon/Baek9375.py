from sys import stdin
from itertools import combinations

input = stdin.readline

T = int(input())

# combination 사용: 시간초과


def fashion():
    N = int(input())
    D = dict()
    for _ in range(N):
        val, key = input().split()
        if key not in D.keys():
            D[key] = [val]
        else:
            D[key].append(val)

    values = list(D.values())
    length = len(values)
    result = sum(values)
    li = [i for i in range(length)]
    for i in range(1, length):
        combs = combinations(li, i + 1)
        temp = 1
        for comb in combs:
            for c in comb:
                temp *= values[c]
        result += temp
    return result


for _ in range(T):
    print(fashion())
