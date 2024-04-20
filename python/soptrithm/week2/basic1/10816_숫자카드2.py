from sys import stdin
from collections import Counter
from bisect import bisect_left, bisect_right

input = stdin.readline

n = int(input())
sanggeun = list(map(int, input().split()))

m = int(input())
numbers = list(map(int, input().split()))


def solve_with_counter():
    global sanggeun, numbers, m, n
    counter = Counter(sanggeun)

    for num in numbers:
        print(counter[num], end=' ')

def solve_with_binary_search():
    global sanggeun, numbers, m, n
    sanggeun.sort()
    for num in numbers:
        r = bisect_right(sanggeun, num)
        l = bisect_left(sanggeun, num)
        print(r - l, end=" ")

solve_with_binary_search()