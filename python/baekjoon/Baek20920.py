from sys import stdin 
from collections import Counter

input = stdin.readline 

# 영어 단어 복합 우선순위 정렬

# 1. 자주 나오는 단어일수록 앞에 배치한다.
# 2. 해당 단어의 길이가 길수록 앞에 배치한다.
# 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
# +) 일정 길이 이상의 단어만 암기

counter = Counter()

N, M = map(int, input().split(" "))

for i in range(N):
  word = input().rstrip()
  # 일정 길이 이상 단어만 암기
  if len(word) < M:
    continue
  
  counter.update([word])

count_dict = dict()
for key, val in counter.items():
  if val not in count_dict.keys():
    count_dict[val] = [key]
  else:
    count_dict[val].append(key)

# dict로 1차 분류
for item in sorted(count_dict.items(),reverse=True):
  # lambda 식으로 2차, 3차 분류
  sorted_list = sorted(item[1], key=lambda x: (-len(x), x))
  for element in sorted_list:
    print(element)