from sys import stdin 

input = stdin.readline

def uclidean(x, y):
  r = x % y 
  if r == 0:
    return y 
  return uclidean(y, r)

N = int(input())

trees = []
for _ in range(N):
  trees.append(int(input()))

min_gap = trees[1] - trees[0]
for i in range(1, N):
  current = trees[i]
  prev = trees[i - 1]
  gap = current - prev 
  min_gap = uclidean(max(gap, min_gap), min(gap, min_gap))

result = 0
for i in range(1, N):
  after = trees[i]
  prev = trees[i-1]
  result += ((after - prev) // min_gap - 1)
print(result)