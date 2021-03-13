#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (15)
int N;
struct Counsel{
	int t;
	int p;
};

Counsel C[MAXN+10];
int DP[MAXN+10];

void inputData()
{
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> C[i].t >> C[i].p;
	}
}

int solve()
{
	for(int day=N-1;day>=0;--day){
		if(day+C[day].t<=N){
			DP[day]=std::max(DP[day+1],DP[day+C[day].t]+C[day].p);
		}else{
			DP[day]=DP[day+1];
		}
	}
	return DP[0];
}

int main() {
	inputData();
	cout << solve() << "\n";
	return 0;
}
