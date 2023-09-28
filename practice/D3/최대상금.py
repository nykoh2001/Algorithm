from itertools import combinations

C = int(input())


def dfs(number, count):
    global results, iter
    if count == iter:
        results.append(number)
        return number
    nCr = combinations([i for i in range(len(number))], 2)
    for c in nCr:
        _number = list(number)
        _number[c[0]], _number[c[1]] = _number[c[1]], _number[c[0]]
        _number = "".join(_number)
        dfs(_number, count + 1)


for t in range(1, C + 1):
    results = []

    number, iter = map(str, input().split())
    iter = int(iter)

    _length = len(number)

    remain = 0
    if iter >= _length - 1:
        remain = iter - (_length - 1)
        iter = _length - 1

    dfs(number, 0)
    result = max(results)
    if remain % 2:
        result = list(result)
        result[_length - 1], result[_length - 2] = (
            result[_length - 2],
            result[_length - 1],
        )
        result = "".join(result)
    print(f"#{t} {result}")
