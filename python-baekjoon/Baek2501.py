from sys import stdin 

input = stdin.readline

M, N = map(int, input().split())

def get_measure():
  count = 0
  for i in range(1, 1 + M):
    if M % i == 0:
      count += 1
      if count == N:
        print(i)
        return 
  print(0)
get_measure()