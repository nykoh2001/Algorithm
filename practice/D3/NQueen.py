from copy import copy


def dfs(i: int, j: int, cnt: int, visited: list):
    global N, result
    visited.append(j)
    if cnt == N:
        result += 1
        return True
    for m in range(N):
        valid = True
        for l in range(cnt):
            if m == visited[l] or l + visited[l] == i + 1 + m or l - visited[l] == i + 1 - m:
                valid = False
                break
        if valid:
            dfs(i + 1, m, cnt + 1, copy(visited))


T = int(input())
for t in range(1, T+1):
    N = int(input())
    result = 0
    for i in range(N):
        dfs(0, i, 1, [])

    print(f"#{t} {result}")
