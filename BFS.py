from sys import stdin
from collections import deque
 
# N: 지하철역의 수, M:원하는 목적역의 번호
N,M=map(int,stdin.readline().split())
M-=1
# S: i번역에서 j번 역까지 가는데 걸리는 시간, 0번 역이 숙소가 있는 역
S=[list(map(int,stdin.readline().strip().split())) for _ in range(N)]
 
INF=1000
NIL=-1
 
def BFS():
    # 1.초기화
    que=deque()
    dist=[INF]*N
    path=[NIL]*N
    # 2. 시작위치 큐에 저장
    dist[0]=0
    que.append(0)
    # 3. 반복
    while que:
        cur=que.popleft()
        for next in range(N):
            if dist[next]>dist[cur]+S[cur][next]:
                dist[next]=dist[cur]+S[cur][next]
                path[next]=cur
                que.append(next)
    # 4. 결과리턴
    return dist[M],path
 
def printPATH(path,t):
    if t==-1:
        return
    printPATH(path,path[t])
    print(t+1,end=' ')
 
t,path=BFS()
print(t)
printPATH(path,M)
