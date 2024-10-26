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
    N = int(input())
    l = -2**31
    r = 2**31

    if l<=N and N<r:
        print("Yes")
    else:
        print("No")

# エントリポイント
if __name__ == '__main__':
    main()
