#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

#define MAXN (8)

int C,N;
int check[MAXN+10];
double D[MAXN+10][MAXN+10];

double sol=10000.0;

void inputData()
{
    sol=10000.0;
    for(int i=0;i<MAXN+10;i++){
        check[i]=0;
    }

    scanf("%d",&N);
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            scanf("%lf",&D[i][j]);
        }
    }
}

void DFS(int n, int s,double totalDist)
{
    if(totalDist > sol) return;
    if(n==N){
        sol=min(sol,totalDist);
        return;
    }

    for(int i=0;i<N;i++){
        if(check[i]==0){
            check[i]=1;
            if(n==0){
                DFS(n+1,i,totalDist);
            }else{
                DFS(n+1,i,totalDist+D[s][i]);
            }

            check[i]=0;
        }
    }
}

void solve()
{
    DFS(0,0,0.0);
}

int main()
{
    scanf("%d",&C);
    for(int c=0;c<C;c++){
        inputData();
        solve();
        printf("%.10lf\n",sol);
    }
    return 0;
}
