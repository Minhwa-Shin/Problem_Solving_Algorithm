#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100
#define MAXK ((int)(1e5))

int N,K;
int W[MAXN+10];
int V[MAXN+10];
int DP[MAXN+10][MAXK+10];

void inputData()
{
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> W[i] >> V[i];
	}
}

int solve()
{
	for(int n=1;n<=N;n++){
		for(int k=1;k<=K;k++){
			if(W[n]>k){
				DP[n][k]=DP[n-1][k];
			}else{
				DP[n][k]=max(DP[n-1][k],DP[n-1][k-W[n]]+V[n]);
			}
		}
	}
	
	return DP[N][K];
}

int main()
{
	int ans=-1;
	inputData();
	ans=solve();
	cout << ans << "\n";
}
