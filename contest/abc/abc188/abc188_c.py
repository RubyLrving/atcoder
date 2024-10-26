'''
oj t -c "python3 main.py"
N = int(input())
A = list(map(int, input().split()))
B = [] * N
'''
 
import math
import heapq
import queue
import itertools
from functools import reduce
from collections import deque
 
# main
def main():
    N = int(input())
    A = list(map(int, input().split()))
 
    que = deque()
    for i in range(0, len(A)):
        que.append((i+1, A[i]))
 
    while len(que)>2:
        a1 = que[0]
        a2 = que[1]
        que.popleft()
        que.popleft()
        if a1[1]>a2[1]:
            que.append(a1)
        else:
            que.append(a2)
 
    a1 = que[0]
    a2 = que[1]     
    
    if a1[1]>a2[1]:
        print(a2[0])
    else:
        print(a1[0])
 
# エントリポイント
if __name__ == '__main__':
    main()