from sys import stdin 

input = stdin.readline

# 1. 일정 크기 이상의 수는 완전수가 아닐 것 같다
# 2. 1을 제외한 수 중 약수가 될 수 있는 가장 작은 수는 2
# 3. 극단적으로 1~N//2까지 다 더했을 때 N보다 작으면 제외 처리
# 4. 1~2//N의 합 = (N//2) * (N//2 + 1) / 2

while True:
  num = int(input())
  if num == -1: break
  if (num // 2) * (num //2 + 1) / 2 < num:
    print(f"{num} is NOT perfect.")
    continue
  measures = []
  for i in range(1, num + 1):
    if num % i == 0:
      measures.append(i)
  measures = measures[:-1]
  measure_sum = sum(measures)
  if measure_sum == num:
    print(f"{num} = " + " + ".join(list(map(str, measures))))
  else :
    print(f"{num} is NOT perfect.")
    