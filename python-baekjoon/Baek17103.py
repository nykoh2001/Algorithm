from sys import stdin
import math 

input = stdin.readline

N = int(input())


prime_numbers = [True for _ in range(1000001)]
prime_numbers[0:2] = [False, False]

# 에라토스테네스의 체
# 일정 범위 안의 소수를 한번에 구하기 좋음
for i in range(2, 1000001): # 1000001 ** 0.5로 해도 무관
  if prime_numbers[i]:
    prime_numbers[i] = True
    for j in range(2 * i, 1000001, i):
      prime_numbers[j] = False

for _ in range(N):
  result = 0
  number = int(input())
  for i in range(2, number // 2 + 1):
    # i_prime = prime_numbers[i]
    # if not i_prime: continue
    
    # k = number - i 
    # k_prime = prime_numbers[k]
    # if not k_prime: continue
    if prime_numbers[i] and prime_numbers[number - i]:
      result += 1
    
  print(result)