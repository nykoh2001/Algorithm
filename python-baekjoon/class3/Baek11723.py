from sys import stdin

input = stdin.readline

N = int(input())

s = set()

# set 자료구조에 대해 연습하는 가장 기본적인 문제
# python에는 switch문이 없으므로 if-elif로 구현
# s.__contains__(item) vs item in s: item in s 형식이 시간 측면에서 아주 약간 효율적

for i in range(N):
    op = input().split()
    if len(op) == 1:
        operator = op[0]
    else:
        operator, operand = op
        operand = int(operand)
    if operator == "add":
        s.add(operand)
    elif operator == "remove" and s.__contains__(operand):
        s.remove(operand)
    elif operator == "check":
        print(int(s.__contains__(operand)))
    elif operator == "toggle":
        if s.__contains__(operand):
            s.remove(operand)
        else:
            s.add(operand)
    elif operator == "all":
        s = set([i for i in range(1, 21)])
    elif operator == "empty":
        s.clear()
