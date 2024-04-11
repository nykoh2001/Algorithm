import math
from sys import stdin

input = stdin.readline

# math
# prime number
# seive of eratosthenes

def bertrand():
    numbers = [1 for _ in range(123456 * 2 + 1)]
    for i in range(2, 123456 * 2 + 1):
        if numbers[i] == 0:
            continue
        for j in range(2 * i, 123456 * 2 + 1, i):
            numbers[j] = 0
    while True:
        num = int(input())
        if num == 0:
            break
        print(sum(numbers[num + 1 : 2 * num + 1]))



bertrand()