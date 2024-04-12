from sys import stdin

input = stdin.readline

# stack

def rooftop_garden():
    n = int(input())
    # pop이 발생하는 시점 - 자신보다 높거나 같은 빌딩이 나타났을 때
    # 자신 - stack의 top
    result = 0
    buildings = [int(input())]
    for _ in range(n - 1):
        building = int(input())
        top = buildings[-1]

        if top <= building:
            while len(buildings) > 0 and top <= building:
                buildings.pop()
                if len(buildings) == 0:
                    break
                top = buildings[-1]
                result += len(buildings)
        buildings.append(building)

    while len(buildings) > 0:
        buildings.pop()
        if len(buildings) == 0:
            break
        result += len(buildings)
    print(result)


rooftop_garden()