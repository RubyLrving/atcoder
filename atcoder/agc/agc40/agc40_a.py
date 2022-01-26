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

    total = 0
    dp = [0] * (len(S)+1)
    for i in range(0, len(S)):
        if S[i] == '<':
            dp[i+1] = max(dp[i+1], dp[i]+1)
    for i in range(len(S)-1, 0, -1):
        if S[i] == '>':
            dp[i] = max(dp[i], dp[i+1]+1)
    
    print(sum(dp))

# エントリポイント
if __name__ == '__main__':
    main()