#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN (7)
int N,M;
int Permutation[MAXN+10];

void inputData()
{
    scanf("%d %d",&N,&M);
}

void printPermutation(int n)
{
    for(int i=1;i<n;i++){
        printf("%d ",Permutation[i]);
    }
    printf("\n");
}

void Perm(int n)
{
    if(n>M){
        printPermutation(n);
        return;
    }
    for(int i=1;i<=N;i++){
        Permutation[n]=i;
        Perm(n+1);
    }
}

void solve()
{
    Perm(1);
}

int main()
{
    inputData();
    solve();
    return 0;
}
