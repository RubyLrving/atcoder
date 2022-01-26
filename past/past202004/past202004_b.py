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

# main
def main():
    S = str(input())

    na = S.count('a')
    nb = S.count('b')
    nc = S.count('c')

    x = max(na, nb, nc)
    
    if x == na:
        print('a')
    elif x == nb:
        print('b')
    elif x == nc:
        print('c')

# エントリポイント
if __name__ == '__main__':
    main()