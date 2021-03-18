#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN ((int)1e5)
int N,S;
int A[MAXN+10];

void inputData()
{
	cin >> N >> S;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
}

int solve()
{
	int i=0,j=0,minLen=200000;
	
	int sum=0;
	while(i<N){
		if(sum < S){
			sum+=A[i++];
		}else if(sum >=S){
			minLen=min(minLen,i-j);
			sum-=A[j++];
		}
	}
	
	while(sum >= S && j<N){
		minLen=min(minLen,i-j);
		sum-=A[j++];
	}
	
    if(minLen==200000) return 0;
	return minLen;
}

int main() {
	inputData();
	cout << solve();
	return 0;
}
