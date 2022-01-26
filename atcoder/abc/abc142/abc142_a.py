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

def my_lcm_base(x, y):
    return (x * y) // math.gcd(x, y)

# main
def main():
    N = int(input())
    res=0
    cnt=1
    while(cnt<=N):
        if cnt%2==1:
            res+=1
        cnt+=1
    
    print(res/N)

# エントリポイント
if __name__ == '__main__':
    main()