#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN (100)
int C;
int N;
int MAP[MAXN+10][MAXN+10];
int Visit[MAXN+10][MAXN+10];

void inputData()
{
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> MAP[i][j];
		}
	}
}

void BFS(int sR,int sC)
{
	pair<int,int> cur;
	int nr,nc;
	int dr[]={1,0};
	int dc[]={0,1};
	
	memset(Visit,0,sizeof(Visit));
	queue<pair<int,int>> que;
	
	Visit[sR][sC]=1;
	que.push(make_pair(sR,sC));
	
	while(!que.empty()){
		cur=que.front(); que.pop();
		if(MAP[cur.first][cur.second]==0){
			cout << "YES" << "\n";
			return;
		}
		for(int i=0;i<2;i++){
			nr=cur.first+dr[i]*MAP[cur.first][cur.second];
			nc=cur.second+dc[i]*MAP[cur.first][cur.second];
			if(nr>=N||nc>=N) continue;
			if(!Visit[nr][nc]){
				Visit[nr][nc]=1;
				que.push(make_pair(nr,nc));
			}
		}
	}
	
	cout << "NO" << "\n";
	return;
}

void solve()
{
	BFS(0,0);
}

int main()
{
	cin >> C;
	for(int i=0;i<C;i++){
		inputData();
		solve();
	}
	return 0;
}
