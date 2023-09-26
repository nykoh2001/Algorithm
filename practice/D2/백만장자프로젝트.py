from sys import stdin

input = stdin.readline

T = int(input())

for i in range(T):
    N = int(input())
    numbers = list(map(int, input().split()))

    benefit = 0
    maximum = 0
    for j in range(N - 1, -1, -1):
        if maximum < numbers[j]:
            maximum = numbers[j]
            continue

        benefit += maximum - numbers[j]
    print(f"#{i+1} {benefit}")
