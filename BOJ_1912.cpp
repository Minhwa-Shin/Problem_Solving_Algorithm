#include <iostream>
using namespace std;

#define MAXN ((int)1e5)
int N;
int A[MAXN+10];
int DP[MAXN+10];

void inputData()
{
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
}

int solve()
{
    int sol;
    sol=DP[0]=A[0];
    for(int i=1;i<N;i++){
        DP[i]=max(DP[i-1]+A[i],A[i]);
        sol=max(sol,DP[i]);
    }
    return sol;
}

int main()
{
    inputData();
    cout << solve() << endl;
    return 0;
}
