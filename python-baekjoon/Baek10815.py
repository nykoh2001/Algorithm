from sys import stdin 

input = stdin.readline

N = int(input())

sang_s = set(map(int, input().split()))
  
M = int(input())
result = [int(x in sang_s) for x in list(map(int, input().split()))]

print(*result)