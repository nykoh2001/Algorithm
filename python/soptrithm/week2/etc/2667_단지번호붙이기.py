from sys import stdin
from collections import deque

input = stdin.readline

n = int(input())

graph = [list(map(int, input().strip())) for _ in range(n)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

result = []

for i in range(n):
    for j in range(n):
        if graph[i][j] != 1:
            continue

        if graph[i][j] == 1:
            building_cnt = 0
            queue = deque([[i, j]])
            graph[i][j] = 0

            while queue:
                y, x = queue.popleft()
                building_cnt += 1
                for k in range(4):
                    ny = y + dy[k]
                    nx = x + dx[k]

                    if 0 <= ny < n and 0 <= nx < n and graph[ny][nx] == 1:
                        queue.append([ny, nx])
                        graph[ny][nx] = 0

            result.append(building_cnt)

print(len(result))
print(*sorted(result), sep="\n")
