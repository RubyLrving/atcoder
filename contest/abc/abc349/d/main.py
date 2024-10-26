'''
oj t -c "python3 ./main.py" -d ./tests/
python3 ./main.py < ./input.txt
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
from string import ascii_lowercase

# main
def main():
    L, R = map(int, input().split())
    ans = []
    while L != R:
        i = 0
        while L % pow(2, i+1) == 0 and L+pow(2, i+1) <= R:
            i += 1
        # print(L, i, pow(2,i), L+pow(2, i))
        ans.append([L, L+pow(2, i)])
        L += pow(2, i)

    print(len(ans))
    for l, r in ans:
        print(l, r)
    
    return

# エントリポイント
if __name__ == '__main__':
    main()