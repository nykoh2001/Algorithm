from sys import stdin 

input = stdin.readline

N, M, K = map(int, input().split())

board = []

for _ in range(N):
  board.append(input())

line = [("W".join(("B" * (K // 2)) + (K%2) * "B")) + ((K+1)%2) * "W", ("B".join(("W" * (K // 2)) + (K%2) * "W")) + ((K+1)%2) * "B"]
board0 = [line[i%2] for i in range(K)]
board1 = [line[i%2] for i in range(1, K+1)]

result = 10000001
for j in range(M-K+1):
  change_cells0, change_cells1 = [], []
  
  for ii in range(0, N):
    current_line = board[ii][j:j+K]
    temp0, temp1 = 0, 0
    
    for i in range(K):
      if current_line[i] != board0[ii][i]:
        temp0 += 1
      if current_line[i] != board1[ii][i]:
        temp1 += 1
   
    change_cells0.append(temp0)
    change_cells1.append(temp1)
  
  min0 = [sum(change_cells0[i:i+K]) for i in range(N-K+1)]
  min1 = [sum(change_cells1[i:i+K]) for i in range(N-K+1)]
  result = min(result, min(min0), min(min1))

print(result)