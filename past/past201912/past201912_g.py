'''
oj t -c "python3 main.py"
N = int(input())
A = list(map(int, input().split()))
B = [] * N
sys.setrecursionlimit(1000000)
'''

import sys
import math
import heapq
import itertools
from collections import deque
from functools import reduce

def has_bit(n, i):
    return (n & (1<<i)>0)

# main
def main():
    N = int(input())
    A = []
    for i in range(0, N-1):
        lst = list(map(int, input().split()))
        A.append([0]*(i+1) + lst)

    ALL = 1<<N
    happy = [0] * ALL

    for n in range(ALL):
        for i in range(N):
            for j in range(i+1, N):
                if has_bit(n, i) and has_bit(n, j):
                    happy[n] += A[i][j]

    ans = -10**100

    for n1 in range(ALL):
        for n2 in range(ALL):
            if n1&n2>0:
                continue
            n3 = ALL-1 - (n1|n2)
            ans = max(ans, happy[n1] + happy[n2] + happy[n3])

    print(ans)





# エントリポイント
if __name__ == '__main__':
    main()
