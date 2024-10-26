n = int(input())
A = list(map(int, input().split()))
 
res = 0
for i in range(0, n):
    d = A[i]
    for j in range(i, n):
        if A[j] <= d:
            d = A[j]
        res = max(d * (j - i + 1), res)
 
print(res)
