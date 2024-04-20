from sys import stdin

input = stdin.readline


def bfs(graph):
    global n, m
    queue = [[1, 1, 1]]
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    while queue:
        current = queue.pop(0)
        if current[:2] == [n, m]:
            return current[2]

        for i in range(4):
            ny = current[0] + dy[i]
            nx = current[1] + dx[i]
            if 1 <= ny <= n and 1 <= nx <= m and graph[ny][nx] == 1:
                queue.append([ny, nx, current[2] + 1])
                graph[ny][nx] = 0




n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for i in range(n):
    graph[i + 1] = list(map(int, input().strip()))
    graph[i + 1].insert(0, 0)

print(bfs(graph))