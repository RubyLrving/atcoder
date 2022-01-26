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
    A, B, C = list(map(int, input().split()))

    if C==1:
        if A>B:
            print(">")
        elif A<B:
            print("<")
        else:
            print("=")
    elif C%2==0:
        A = A*A
        B = B*B
        if A>B:
            print(">")
        elif A<B:
            print("<")
        else:
            print("=")
    elif C%2==1:
        A = A*A*A
        B = B*B*B
        if A>B:
            print(">")
        elif A<B:
            print("<")
        else:
            print("=")


# エントリポイント
if __name__ == '__main__':
    main()
