from sys import stdin

input = stdin.readline

# ENTER가 입력될 때마다 카운팅 초기화
# set에 추가하고 그 크기를 구하여 계산

# 케이스 분류 : 
#   1. ENTER인 경우
#   2. ENTER가 아닌 경우

N = int(input())

count_set = set()
count = 0
for i in range(N):
  string = input().rstrip()
  if (string == "ENTER"):
    count += len(count_set)
    count_set = set()
  else:
    count_set.add(string)
count += len(count_set)
print(count)
    