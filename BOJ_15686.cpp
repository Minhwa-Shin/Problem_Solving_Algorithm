#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

#define MAXN (50)
int N,M;
int MAP[50+2][50+2];

vector<pair<int,int>> store;
vector<pair<int,int>> house;

int minChickDist=INT_MAX;

void inputData()
{
    cin >> N >> M;
    for(int r=1;r<=N;r++){
        for(int c=1;c<=N;c++){
            cin >> MAP[r][c];
            if(MAP[r][c]==2){ //치킨집
                store.push_back(make_pair(r,c));
            }else if(MAP[r][c]==1){ //집
                house.push_back(make_pair(r,c));
            }
        }
    }
}

void DFS(int n,int s,vector<pair<int,int>>& picked)
{
    if(n==M){
        //도시의 치킨 거리 계산
        int chickDist=0;
        for(int i=0;i<house.size();i++){
            int minDist=INT_MAX;
            for(int j=0;j<picked.size();j++){
                minDist=min(minDist,abs(picked[j].first-house[i].first)+abs(picked[j].second-house[i].second));
            }
            chickDist+=minDist;
        }
        minChickDist=min(minChickDist,chickDist);
        return;
    }

    for(int i=s;i<store.size();i++){
        picked.push_back(store[i]);
        DFS(n+1,i+1,picked);
        picked.pop_back();
    }
}

void solve()
{
    vector<pair<int,int>> picked;
    DFS(0,0,picked);
    cout << minChickDist << "\n";
}

int main()
{
    inputData();
    solve();
    return 0;
}
