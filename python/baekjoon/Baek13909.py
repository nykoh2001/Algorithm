from sys import stdin, exit
import math

input = stdin.readline

# 초반 몇개 나열
# 이전 식과 비교했을 때 마지막 숫자 값만 바뀜
# 약수의 개수가 짝수인 곳은 0, 약수의 개수가 홀수인 곳은 1이 됨
# 1~N까지 중 제곱수의 개수가 곧 결과 값
# N >= K^2인 K의 최대값

N = int(input())
    
for i in range(N, 0, -1): 
  if math.sqrt(i).is_integer():
    print(int(math.sqrt(i)))
    exit()