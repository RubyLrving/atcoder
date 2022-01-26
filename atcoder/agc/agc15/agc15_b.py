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

    res = 0
    for i in range(0, len(S)):
        if S[i] == "U":
            res += len(S) - (i+1)
            res += (i)*2
        else:
            res += (len(S) - (i+1))*2
            res += i

    print(res)

# エントリポイント
if __name__ == '__main__':
    main()