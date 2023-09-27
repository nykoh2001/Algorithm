T = int(input())

for i in range(T):
    numbers = list(map(int, input().split()))
    minimum = 10001
    maximum = -1
    _sum = 0
    for num in numbers:
        if num < minimum:
            minimum = num
        if num > maximum:
            maximum = num
        _sum += num

    print(f"#{i+1} {round((_sum - minimum - maximum) / 8)}")
