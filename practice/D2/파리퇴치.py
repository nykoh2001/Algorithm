T = int(input())

for t in range(1, T + 1):
    N, M = list(map(int, input().split()))
    area = []
    for i in range(N):
        area.append(list(map(int, input().split())))

    paris = 0
    for i in range(N - M + 1):
        for j in range(N - M + 1):
            current_paris = 0
            for k in range(M):
                current_paris += sum(area[i + k][j : j + M])
            if current_paris > paris:
                paris = current_paris
    print(f"#{t} {paris}")
