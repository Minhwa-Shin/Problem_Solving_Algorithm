#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN ((int)2e5)
int N,C;
vector<int> X;

void inputData()
{
    int x;
    cin >> N >> C;
    for(int i=0;i<N;i++){
        //cin >> X[i];
        cin >> x; X.push_back(x);
    }
}

int lb(int s, int e,int t)
{
    if(X[e]<t) return e+1;

    int m;
    while(s<e){
        m=(s+e)/2;
        if(X[m]<t){
            s=m+1;
        }else{
            e=m;
        }
    }
    return s;
}

bool isPossible(int d)
{
    int cnt=C;
    for(int i=0;i<N;){
        if(--cnt==0) return true;
        i=lb(i+1,N-1,X[i]+d);
    }
    return false;

    /*auto it=begin(X);
    while(it!=end(X)){
        if(--cnt==0) return true;
        it=lower_bound(it+1,end(X),(*it)+d);
    }*/

    return false;
}

int bs(int s,int e)
{
    int m,sol=0;
    while(s<=e){
        m=(s+e)/2;
        if(isPossible(m)){
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
    sort(begin(X),begin(X)+N);
    return bs(1,X[N-1]);
}

int main()
{
    inputData();
    cout << solve() << endl;
    return 0;
}
