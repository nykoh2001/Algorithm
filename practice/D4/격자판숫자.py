T = int(input())

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def dfs(i: int, j: int, cnt: int, number: str):
    global numbers, _set, dx, dy

    _number = number + str(numbers[i][j])
    if cnt == 7:
        _set.add(number)
        return

    for k in range(4):
        current_x = i + dx[k]
        current_y = j + dy[k]
        if current_x in range(4) and current_y in range(4):
            dfs(current_x, current_y, cnt + 1, _number)


for t in range(1, T+1):
    numbers = []
    _set = set()
    for i in range(4):
        numbers.append(list(map(int, input().split())))

    for i in range(4):
        for j in range(4):
            dfs(i, j, 0, "")

    print(f"#{t} {len(_set)}")
