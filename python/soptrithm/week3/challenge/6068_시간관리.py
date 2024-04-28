from sys import stdin

input = stdin.readline

def scheduling():
    n = int(input())
    tasks = []
    for i in range(n):
        tasks.append(list(map(int, input().split())))

    tasks.sort(key=lambda x: x[1], reverse=True)
    wakeup_time = tasks[0][1]
    for task in tasks:
        # task start time
        wakeup_time = min(task[1], wakeup_time) - task[0]
    if wakeup_time < 0:
        return -1
    return wakeup_time

print(scheduling())

