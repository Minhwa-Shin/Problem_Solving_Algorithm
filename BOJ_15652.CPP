#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN (8)
int N,M;
int Combination[MAXN+10];

void inputData()
{
    scanf("%d %d",&N,&M);
}

void printCombination(int n)
{
    for(int i=1;i<n;i++){
        printf("%d ",Combination[i]);
    }
    printf("\n");
}

void Comb(int n,int s)
{
    if(n>M){
        printCombination(n);
        return;
    }
    for(int i=s;i<=N;i++){
        Combination[n]=i;
        Comb(n+1,i);
    }
}

void solve()
{
    Comb(1,1);
}

int main()
{
    inputData();
    solve();
    return 0;
}
