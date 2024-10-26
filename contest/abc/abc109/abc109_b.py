N = int(input())

A = [""] * N
is_ok = True
for i in range(0, N):
  S = str(input())
  if A.count(S) > 0:
    is_ok = False
    
  A[i] = S
  if i>0:
    if A[i-1][len(A[i-1])-1] != A[i][0]:
      is_ok = False
  
if(is_ok):
  print("Yes")
else:
  print("No")
  