#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (100000)
int N,X;
int A[MAXN+10];

void inputData()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	cin >> X;
}

int solve()
{
	int i=0,j=N-1,cnt=0,sum=0;
	
	sort(begin(A),begin(A)+N);
	while(i<j){
		sum=A[i]+A[j];
		if(sum==X){
			++cnt; ++i; --j;
		}else if(sum>X){
			--j;
		}else{
			++i;
		}
	}
	return cnt;
}

int main()
{
	inputData();
	cout << solve();
	return 0;
}
