#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN ((int)1e6)
int N,M;
int T[MAXN+10];
int maxT=0;

void inputData()
{
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> T[i];
        maxT=max(maxT,T[i]);
    }
}

long long checktotal(long long H)
{
    long long total=0;
    for(int i=0;i<N;i++){
        if(T[i]>H){
            total+=T[i]-H;
        }
    }
    return total;
}

int bs(long long s,long long e)
{
    int sol=-1;
    long long m;
    while(s<=e){
        m=(s+e)/2;
        if(checktotal(m)>=M){
            if(sol<m) sol=m;
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return sol;
}

int solve()
{
    return bs(0,maxT);
}

int main()
{
    inputData();
    cout << solve() << endl;
    return 0;
}
