from sys import stdin
from itertools import combinations

# bruteforce
# sort

input = stdin.readline

def seven_dwarfs():
    # initialize dwarf heights
    dwarfs = []

    for _ in range(9):
        dwarfs.append(int(input().rstrip()))

    # sum(all) - (2 dwarfs' height)
    whole_sum = sum(dwarfs)
    dwarf_pairs = list(combinations(dwarfs, 2))
    for pair in dwarf_pairs:
        if whole_sum - sum(pair) == 100:
            real_dwarfs = [d for d in dwarfs if d not in pair]
            print("\n".join(map(str, sorted(real_dwarfs))))
            return

seven_dwarfs()