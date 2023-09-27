N = int(input())

result = []
for i in range(1, N + 1):
    str_i = str(i)
    hypen = ""
    for s in str_i:
        if int(s) % 3 == 0 and int(s) > 0:
            hypen += "-"
    if hypen == "":
        result.append(str_i)
    else:
        result.append(hypen)

print(" ".join(result))
