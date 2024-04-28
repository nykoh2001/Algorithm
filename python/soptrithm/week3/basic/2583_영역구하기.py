from sys import stdin
from collections import deque

input = stdin.readline

def get_area():
    dm = [1, 0, -1, 0]
    dn = [0, 1, 0, -1]

    m, n, k = map(int, input().split())
    area = [[0 for _ in range(n)] for _ in range(m)]
    result = []

    for i in range(k):
        n_1, m_1, n_2, m_2 = map(int, input().split())
        for _m in range(m_1, m_2):
            for _n in range(n_1, n_2):
                area[_m][_n] = 1

    for i in range(m):
        for j in range(n):
            if area[i][j] == 0:
                q = deque([[i, j]])
                area[i][j] = 1
                current_area = 0
                while q:
                    current = q.popleft()
                    current_area += 1
                    for k in range(4):
                        nm = current[0] + dm[k]
                        nn = current[1] + dn[k]
                        if 0 <= nm < m and 0<= nn < n and area[nm][nn] == 0:
                            area[nm][nn] = 1
                            q.append([nm, nn])

                result.append(current_area)

    print(len(result))
    print(*sorted(result))

get_area()

