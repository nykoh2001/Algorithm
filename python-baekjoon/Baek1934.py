from sys import stdin 

input = stdin.readline

N = int(input())

# 유클리드 호제 => 최대공약수

## 유클리드 호제
# x, y의 최대 공약수 == y, x % y의 최대 공약수

# 최소공배수 = 두 수의 곱 // 최대공약수

def uclidean(x, y):
  r = x % y
  if r == 0:
    return y 
  return uclidean(y, r)

for i in range(N):
  x, y = map(int, input().split())
  print(x * y // uclidean(max(x, y), min(x, y)))