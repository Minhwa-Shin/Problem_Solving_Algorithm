#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX (100)
int M,N,H;
int B[MAX+2][MAX+2][MAX+2];
int Check[MAX+2][MAX+2][MAX+2];

struct Coord{
    int z; int y; int x;
};

queue<Coord> que;

int dz[]={0,0,0,0,-1,1};
int dy[]={-1,1,0,0,0,0};
int dx[]={0,0,-1,1,0,0};

int tomato_0 = 0;

void inputData()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> H;
    for(int z=0;z<H;++z){
        for(int y=0;y<N;++y){
            for(int x=0;x<M;++x){
                cin >> B[z][y][x];
                if(B[z][y][x]==0){
                    tomato_0++;
                }else if(B[z][y][x]==1){
                    que.push({z,y,x});
                }
            }
        }
    }
}

int BFS()
{
    Coord cur,next;
    while(!que.empty()){
        cur=que.front(); que.pop();
        for(int i=0;i<6;i++){
            next.z=cur.z+dz[i]; next.y=cur.y+dy[i]; next.x=cur.x+dx[i];
            if(next.z<0||next.z>=H||next.y<0||next.y>=N||next.x<0||next.x>=M) continue;
            if(B[next.z][next.y][next.x]==0){
                B[next.z][next.y][next.x]=B[cur.z][cur.y][cur.x]+1;
                tomato_0--;
                que.push(next);
            }
        }
    }
    if(tomato_0>0) return -1;
    return B[cur.z][cur.y][cur.x]-1;
}

int solve()
{
    if(tomato_0==0) return 0;
    return BFS();
}

int main()
{
    inputData();
    cout << solve() << "\n";
    return 0;
}
