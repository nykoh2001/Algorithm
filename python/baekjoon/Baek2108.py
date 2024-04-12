from sys import stdin 
from collections import Counter

input = stdin.readline

N = int(input())

nums = []

for i in range(N):
  num = int(input())
  nums.append(num)

nums = sorted(nums)
length = len(nums)

cnts = Counter(nums)
most_commons = cnts.most_common()

### 1. 최빈값이 여러 개인 경우 두번째로 작은 값 출력
current_common = 0
c_vals = []
for x, y in most_commons:
  if current_common > y:
    break
  current_common = y
  c_vals.append((x, y))

if len(c_vals) == 1:
  common_val = c_vals[0][0]
else :
  ## most_common을 통해 반환된 값들은 정렬되어 있지 않음을 고려
  c_vals = sorted(c_vals)
  common_val = c_vals[1][0]


### 2. mean에서 round를 취하면 -0이 되는 경우 고려
mean = round(sum(nums) / length)
mean = abs(mean) if mean == 0 else mean
print(mean)
print(nums[length // 2])
print(common_val)
print(nums[-1] - nums[0])