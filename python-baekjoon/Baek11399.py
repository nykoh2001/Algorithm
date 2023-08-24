from sys import stdin

input = stdin.readline

# S(n) = S(n-1) + a(n), S(n)의 합이 최종 답
# 오름차순으로 정렬 시 대기 시간의 합이 최소가 됨
# 전에 사용된 결과를 사용

N = int(input())
people = sorted(list(map(int, input().split())))
for i in range(N - 1):
    people[i + 1] = people[i] + people[i + 1]

print(sum(people))
