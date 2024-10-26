'''
oj t -c "python3 main.py"
N = int(input())
A = list(map(int, input().split()))
B = [] * N
'''

import math
import heapq
import itertools
from functools import reduce

def score_total(S):
    res = 0
    for i in range(1, 10):
        cnt = S.count(str(i))
        res += i * (10 ** cnt)
    return res

# main
def main():
    k = int(input())
    S = str(input())[0:4]
    T = str(input())[0:4]

    D = [k] * 10
    D[0] = 0
    for i in range(0, len(S)):
        D[int(S[i])] -= 1
    for i in range(0, len(T)):
        D[int(T[i])] -= 1

    res = 0
    for i in range(1, 10):
        if D[i] == 0:
            continue
        for j in range(1, 10):
            if i == j or D[j] == 0:
                continue
            if score_total(S+str(i)) > score_total(T+str(j)):
                res += D[i] * D[j]

    for i in range(1, 10):
        if D[i] < 2:
            continue
        if score_total(S+str(i)) > score_total(T+str(i)):
            res += D[i] * (D[i]-1)

    print(res / ((9*k-8) * (9*k-9)))
        

# エントリポイント
if __name__ == '__main__':
    main()