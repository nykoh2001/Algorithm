from sys import stdin 

input = stdin.readline

numerator0, denominator0 = map(int ,input().split())
numerator1, denominator1 = map(int ,input().split())

def uclidean(x, y):
  r = x % y 
  if r == 0:
    return y 
  return uclidean(y, r)

denominator = denominator0 * denominator1 
numerator = numerator0 * denominator1 + numerator1 * denominator0

uc = uclidean(max(denominator, numerator), min(denominator, numerator))

print(numerator // uc, denominator // uc)