#include <iostream>
using namespace std;

#define MAXN (8)
int N,M;
int Combination[MAXN+10];

void inputData()
{
    cin >> N >> M;
}

void printCombination(int n)
{
    for(int i=1;i<n;i++){
        cout << Combination[i] << " ";
    }
    cout << endl;
}

void MakeCombination(int n,int s)
{
    if(n>M){
        printCombination(n);
        return;
    }
    for(int i=s;i<=N;i++){
        Combination[n]=i;
        MakeCombination(n+1,i+1);
    }
}

void solve()
{
    MakeCombination(1,1);
}

int main()
{
    inputData();
    solve();
    return 0;
}
