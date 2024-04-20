from sys import stdin

input = stdin.readline


N, M, V = map(int, input().split())

graph = [[] for _ in range(N + 1)]

def bfs(node):
    global graph
    visited = [False for _ in range(N + 1)]
    queue = [node]
    visited[node] = True

    while len(queue) > 0:
        vertex = queue.pop(0)
        print(vertex, end=" ")
        for neighbor in graph[vertex]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

def dfs(node, visited: list):
    global graph
    print(node, end=" ")
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor, visited)

for i in range(M):
    v1, v2 = map(int, input().split())

    graph[v1].append(v2)
    graph[v2].append(v1)

for i in range(N+1):
    graph[i].sort()

dfs(V, [False for _ in range(N + 1)])
print()
bfs(V)