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

    NxN = N*N
    print(NxN // math.factorial(N))


# エントリポイント
if __name__ == '__main__':
    main()
