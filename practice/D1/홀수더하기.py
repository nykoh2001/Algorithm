N = int(input())
for i in range(N):
    numbers = list(map(int, input().split()))
    result = 0
    for num in numbers:
        if num % 2 == 1:
            result += num
    print(f"#{i+1} {result}\n")
