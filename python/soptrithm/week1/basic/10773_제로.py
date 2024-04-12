from sys import stdin

input = stdin.readline

# stack

def zero():
    stack = []
    n = int(input())
    for _ in range(n):
        num = int(input().rstrip())
        if num == 0:
            stack.pop()
        else:
            stack.append(num)
    print(sum(stack))

zero()