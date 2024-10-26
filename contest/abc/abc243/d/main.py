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
    N, X = list(map(int, input().split()))
    S = str(input())

    for i in range(N):
        if S[i] == 'U':
            X = X//2
        elif S[i] == 'L':
            X = X*2
        elif S[i] == 'R':
            X = X*2+1
    
    print(int(X))

# エントリポイント
if __name__ == '__main__':
    main()
