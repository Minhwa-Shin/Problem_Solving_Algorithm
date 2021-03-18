#include <iostream>
using namespace std;

#define MAXN (100)
#define MAXK ((int)1e4)
int n,k;
int Coin[MAXN+10];
int DP[MAXK+10];

void inputData()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> Coin[i];
    }
}

void solve()
{
    DP[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=Coin[i];j<=k;j++){
            DP[j]=DP[j]+DP[j-Coin[i]];
        }
    }
    cout << DP[k] << "\n";
}

int main()
{
    inputData();
    solve();
    return 0;
}
