from sys import stdin

input = stdin.readline

# stack

def tower():
    # 새로운 타워보다 현재 top에 있는 타워의 높이가 낮으면 pop
    max_height = 100_000_000
    n = int(input())
    towers = list(map(int, input().split()))
    towers = [[i + 1, v] for i, v in enumerate(towers)]

    stack = [[0, max_height]]
    result = []
    for t in towers:
        while len(stack) > 0 and stack[-1][1] < t[1]:
            stack.pop()
        result.append(stack[-1][0])
        stack.append(t)

    print(" ".join(map(str, result)))

tower()