#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define MAXN (100000)
int N;
int A[MAXN+10];

void inputData()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
}

void solve()
{
	int i=0,j=N-1,sum=0;
	int minSum=INT_MAX,liquid1=-1,liquid2=N;
	
	sort(begin(A),begin(A)+N);
	while(i<j){
		sum=A[i]+A[j];
		if(abs(sum) < minSum){
			minSum=abs(sum);
			liquid1=A[i]; liquid2=A[j];
		}
		if(sum==0){
			break;
		}else if(sum < 0){
			++i;
		}else{
			--j;
		}
	}
	
	cout << liquid1 << " " << liquid2;
}

int main()
{
	inputData();
	solve();
	return 0;
}
