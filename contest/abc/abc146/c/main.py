'''
oj t -c "python3 ./main.py" -d ./tests/
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
    A, B, X = list(map(int, input().split()))

    ok = 0
    ng = 10**9 + 1

    while abs(ok-ng) > 1:
        mid = (ok + ng) // 2
        d = len(str(mid))
        price = mid * A + B * d
        if X >= price:
            ok = mid
        else:
            ng = mid
    print(ok)

# エントリポイント
if __name__ == '__main__':
    main()
