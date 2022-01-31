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
    N, L, W = list(map(int, input().split()))
    A = list(map(int, input().split()))

    p = 0
    ans = 0
    for i in range(0, N):
        if A[i] >= p:
            ans += (A[i] - p + (W-1)) // W
        if p < A[i] + W:
            p = A[i] + W
    
    ans += (L - p + (W-1)) // W

    print(ans)

# エントリポイント
if __name__ == '__main__':
    main()
