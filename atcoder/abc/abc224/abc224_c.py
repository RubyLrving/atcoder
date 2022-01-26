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

# main
def main():
    N = int(input())
    x = [0] * N
    y = [0] * N
    for i in range(0, N):
        x[i], y[i] = list(map(int, input().split()))

    res=0
    for p in range(0, N):
        for q in range(p+1, N):
            for r in range(q+1, N):
                x1 = x[q] - x[p] 
                x2 = x[r] - x[p] 
                y1 = y[q] - y[p] 
                y2 = y[r] - y[p]
 
                ans = abs((x1 * y2) - (x2 * y1)) / 2
                if ans>0:
                    res = res + 1

    print(res)

# エントリポイント
if __name__ == '__main__':
    main()
