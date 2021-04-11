from sys import stdin
 
#N:지도의 크기
N=int(stdin.readline().rstrip())
#MAP:지도
MAP=[list(map(int,stdin.readline().strip())) for _ in range(N)]
 
number=2
sol=[]
 
d=[(-1,0),(1,0),(0,-1),(0,1)]
 
def DFS(r,c,n):
    if r<0 or r>=N or c<0 or c>=N or MAP[r][c]!=1:
        return 0
 
    MAP[r][c]=n
    ret=1
    for dr,dc in d:
        ret+=DFS(r+dr,c+dc,n)
 
    return ret
 
for r in range(N):
    for c in range(N):
        if MAP[r][c]==1:
            sol.append(DFS(r,c,number))
            number += 1
 
print(number-2)
sol.sort()
for n in sol:
    print(n)
