from sys import stdin

input = stdin.readline

def cumulative_sum(n, m):
    global numbers

    dp = [0 for _ in range(n + 1)]
    for i in range(1, n + 1):
        dp[i] = dp[i-1] + numbers[i-1]

    for i in range(m):
        i, j = map(int, input().split())

        print(dp[j] - dp[i - 1])

n, m = map(int, input().split())
numbers = list(map(int, input().split()))

cumulative_sum(n, m)