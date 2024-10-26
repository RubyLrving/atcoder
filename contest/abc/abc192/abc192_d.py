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

def Base_n_to_10(X,n):
    out = 0
    for i in range(1,len(str(X))+1):
        out += int(X[-i])*(n**(i-1))
    return out

# main
def main():
    S = str(input())
    M = int(input())
    d = 0

    if len(S) == 1:
        if int(S) <= M:
            print(1)
        else:
            print(0)

        return

    for i in range(0, len(S)):
        d = max(d, int(S[i]))

    L = d
    R = M+1
    while (R-L)>1:
        mid = (R+L) // 2
        T = Base_n_to_10(S, mid)
        if T <= M:
            L = mid
        else:
            R = mid
    res = L-d
    print(res)

# エントリポイント
if __name__ == '__main__':
    main()