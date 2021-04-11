from sys import stdin
input=stdin.readline
 
def DFS(s,sum,D,N,K,pSum):
    if sum==K: return True
    if sum>K: return False
    if K-sum > pSum[N]-pSum[s-1]: return False
 
    for i in range(s,N+1):
        if DFS(i+1,sum+D[i],D,N,K,pSum):
            return True
 
    return False
 
def solve():
    # N: 자연수의 개수, K: 확인할 수
    N,K=map(int,stdin.readline().split())
    # D[] : N개의 자연수
    D=[0]
    D.extend(list(map(int,stdin.readline().split())))
    # pSum[] : prefix sum
    pSum=[0]*(N+1)
    for i in range(1,N+1):
        pSum[i]=pSum[i-1]+D[i]
 
    if DFS(1,0,D,N,K,pSum):
        print("YES")
    else:
        print("NO")
 
# T: 테스트 케이스 개수
T=int(stdin.readline().rstrip())
 
for _ in range(T):
    solve()
