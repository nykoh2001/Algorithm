from sys import stdin

input = stdin.readline

"""
divide and conquer
N=2**k
recursion

1. method about keyword "all"
2. is different with initial state
get input with list comprehension
"""

N = int(input())
confetti = [list(map(int, input().split())) for _ in range(N)]
cnt_white, cnt_blue = 0, 0


def check_confetti(i, j, k):
    # 왼쪽 위 꼭짓점의 y좌표, x좌표, 한 변 길이

    global confetti, cnt_white, cnt_blue

    state = confetti[i][j]
    # 색종이의 첫번째 픽셀로 state 초기화

    for I in range(i, i + k):
        for J in range(j, j + k):
            # 색종이의 각 픽셀에 대해 state와 같은지 다른지 확인
            if state != confetti[I][J]:
                # 다른 경우 색종이 4등분 -> 각 조각에 대해 확인 후 종료
                k = k // 2
                check_confetti(i, j, k)
                check_confetti(i + k, j, k)
                check_confetti(i, j + k, k)
                check_confetti(i + k, j + k, k)
                return
    # k가 1이거나 모든 픽셀의 값이 동일한 경우 -> state가 곧 종이의 색임을 고려하여 cnt 값 갱신
    if state:
        cnt_blue += 1
    else:
        cnt_white += 1


check_confetti(0, 0, N)
print(cnt_white)
print(cnt_blue)
