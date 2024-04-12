from sys import stdin
from collections import Counter

input = stdin.readline


def statistics():
    n = int(input())
    nums = []
    for _ in range(n):
        nums.append(int(input()))

    nums = sorted(nums)
    nums_counter = Counter(nums)
    most_common_item = nums_counter.most_common(1)
    most_commons = [mc for mc in nums_counter.most_common() if mc[1] >= most_common_item[0][1]]
    if len(most_commons) == 1:
        most_common = most_commons[0][0]
    else:  # len(most_commons) >= 2:
        most_common = most_commons[1][0]

    print(round(sum(nums) / n))
    print(nums[n // 2])
    print(most_common)
    print(nums[-1] - nums[0])


statistics()
