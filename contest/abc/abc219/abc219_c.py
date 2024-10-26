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
    x = ' ' + str(input())
    N = int(input())

    S = []
    for i in range(0, N):
        s = str(input())
        res=0
        for j in range(0, len(s)):
            res = res + pow(27, 10-1-j) * (x.index(s[j]))
        S.append((res, s))

    S.sort()

    for key, value in S:
        print(value)
    

# エントリポイント
if __name__ == '__main__':
    main()
