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
    N, X, T = list(map(int, input().split()))
 
    res = 0
    cnt = 0
    while cnt<N:
        cnt += X
        res += T
    
    print(res)
 
# エントリポイント
if __name__ == '__main__':
    main()
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
    N, X, T = list(map(int, input().split()))

    res = 0
    cnt = 0
    while cnt<N:
        cnt += X
        res += T
    
    print(res)

# エントリポイント
if __name__ == '__main__':
    main()
