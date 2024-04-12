from sys import stdin

input = stdin.readline

# bruteforce
# implementation

def body_frame():
    n = int(input())
    people = []
    result = [n for _ in range(n)]

    for _ in range(n):
        people.append(list(map(int, input().rstrip().split())))

    for i in range(n):
        current_person = people[i]
        for j in range(n):
            current_comparison = people[j]
            if i != j and not(current_person[0] < current_comparison[0] and current_person[1] < current_comparison[1]):
                # 덩치가 크지 않을 때에
                result[i] -= 1
    print(*result)

body_frame()