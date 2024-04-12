from sys import stdin

input = stdin.readline

# math

def alpha_century():
    t = int(input())

    for _ in range(t):
        start, end = map(int, input().split())
        distance = end - start
        for i in range(1, distance + 1):
            dist_sum = i * (i + 1)
            if dist_sum >= distance:
                if dist_sum - distance < i:
                    result = 2 * i
                else:
                    result = 2 * i - 1
                print(result)
                break


alpha_century()