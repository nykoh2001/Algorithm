from sys import stdin
from collections import deque

input = stdin.readline

m ,n = map(int, input().split())

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

tomatoes = []

queue = deque()

zero_tomatoes = 0
for i in range(n):
    tomatoes_now = list(map(int, input().split()))
    tomatoes.append(tomatoes_now)
    for j in range(m):
        if tomatoes_now[j] == 1:
            queue.append([i, j])
        if tomatoes_now[j] == 0:
            zero_tomatoes += 1

while queue:
    t_r, t_c = queue.popleft()
    for i in range(4):
        nr = t_r + dy[i]
        nc = t_c + dx[i]

        if 0 <= nr < n and 0 <= nc < m and tomatoes[nr][nc] == 0:
            queue.append([nr, nc])
            tomatoes[nr][nc] = tomatoes[t_r][t_c] + 1
            zero_tomatoes -= 1

if zero_tomatoes > 0:
    print(-1)
else:
    print(tomatoes[t_r][t_c] - 1)
