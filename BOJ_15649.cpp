#include <iostream>
using namespace std;

#define MAXN 8

int N, M;

int permutation[MAXN+2];
int check[MAXN+2];

void perm(int n)
{
	int i;
	
	if(n>M){
		for(i=1;i<=M;i++){
			cout << permutation[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(i=1;i<=N;i++){
		if(check[i]==0){
			check[i]=1;
			permutation[n]=i;
			perm(n+1);
			check[i]=0;
		}
	}
}

void solve()
{
	perm(1);
}

int main()
{
	cin >> N >> M;
	solve();
	return 0;
}
