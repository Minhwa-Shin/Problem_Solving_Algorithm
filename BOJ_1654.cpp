#include <iostream>
#include <algorithm>
using namespace std;

#define MAXK ((int)1e4)
int K,N;
int L[MAXK+10];
int maxL=0;

void inputData()
{
    cin >> K >> N;
    for(int k=0;k<K;k++){
        cin >> L[k];
        maxL=max(maxL,L[k]);
    }
}

long long checkCnt(long long m){
    long long cnt=0;
    for(int k=0;k<K;k++){
        cnt+=((long long)L[k]/m);
    }
    return cnt;
}

int bs(long long s,long long e)
{
    long long m,cnt,sol=-1;

    while(s<=e){
        m=(s+e)/2;
        cnt=checkCnt(m);
        if(cnt >= N){
            sol=max(sol,m);
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return sol;
}

int solve()
{
    return bs(1,maxL);
}

int main()
{
    inputData();
    cout << solve() << endl;
    return 0;
}
