#include <iostream>
using namespace std;

int N,K;

void inputData()
{
    cin >> N;
    cin >> K;
}

bool check(int n){
    int cnt=0;
    for(int i=1;i<=N;i++){
        cnt+=min(n/i,N);
    }
    if(cnt>=K) return true;
    return false;
}

int bs(int s,int e)
{
    int m,sol;
    while(s<=e){
        m=(s+e)/2;
        if(check(m)){
            sol=m;
            e=m-1;
        }else{
            s=m+1;
        }
    }
    return sol;
}

int solve()
{
    return bs(1,K);
}

int main()
{
    inputData();
    cout << solve() << endl;
    return 0;
}
