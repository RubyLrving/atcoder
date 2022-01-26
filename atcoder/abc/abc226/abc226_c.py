N = int(input())
data = []
data.append([])
#ok[n]:技nが習得済みかどうか
ok = [False] * (N+1)
#value[n]:技nの習得にかかる時間
value = [0] * (N+1)
for i in range(N):
    temp = list(map(int, input().split()))
    data.append(temp)
    #すぐ習得できるやつは値を記録
    if temp[1] == 0:
        ok[i+1] = True
        value[i+1] = temp[0]
 
 
 
#メモ再帰
def dfs(n):
    if ok[n]:
        return
    for x in data[n][2:]:
        if ok[x]:
            value[n] += value[x]
        
        else:
            dfs(x)
    ok[n] = True
    value[n] += data[n][0]
 
 
dfs(N)
print(value[N])