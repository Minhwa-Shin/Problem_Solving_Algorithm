#include <iostream>
using namespace std;

#define MAXN (100)
int N,M;
int Card[MAXN+10];

int sol=0;
bool BlackJack_Found=false;

void inputData()
{
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> Card[i];
    }
}

void DFS(int n,int s,int sum)
{
    if(n==3){
        if(sum==M){
            sol=M; BlackJack_Found=true;
        }else if(sum<M){
            sol=max(sol,sum);
        }
        return;
    }

    for(int i=s;i<N;i++){
        DFS(n+1,i+1,sum+Card[i]);
        if(BlackJack_Found) return;
    }
}

void solve()
{
    DFS(0,0,0);
}

int main()
{
    inputData();
    solve();
    cout << sol << endl;
    return 0;
}
