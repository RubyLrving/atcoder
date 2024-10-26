L = int(input())
cnt = 1
r = 1
while cnt<=11:
   r = r * cnt
   cnt = cnt + 1
cnt = 1
res = 1
while cnt<=11:
   res = res * (L - cnt)
   cnt = cnt + 1
res = res // r
print(res)