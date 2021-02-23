#include <iostream>
#include <algorithm>
using namespace std;

#define MAX ((int)1e5)
int N,M;
int A[MAX+10];

void inputData()
{
    //cin >> N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        //cin >> A[i];
        scanf("%d",&A[i]);
    }
}

int bs(int s,int e,int t)
{
    int m;
    while(s<=e){
        m=(s+e)/2;
        if(A[m]==t) return 1;
        if(A[m]<t) s=m+1;
        else e=m-1;
    }
    return 0;
}

void solve()
{
    int n;

    sort(begin(A),begin(A)+N);

    //cin >> M;
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        //cin >> n;
        scanf("%d",&n);
        //if(bs(0,N-1,n)){
        if(std::binary_search(begin(A),begin(A)+N,n)){
            printf("%d\n",1);//cout << 1 << endl;
        }else{
            printf("%d\n",0);//cout << 0 << endl;
        }
    }
}

int main()
{
    inputData();
    solve();
    return 0;
}
