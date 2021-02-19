#include <iostream>
using namespace std;

#define MAXN ((int)1e5)
int N;
int D[MAXN+10]; // 도로의 길이
int P[MAXN+10]; // 주유소의 리터당 가격

void inputData()
{
    int i;
    cin >> N;
    for(i=0;i<N-1;i++){
        cin >> D[i];
    }
    for(i=0;i<N;i++){
        cin >> P[i];
    }
}

long long solve()
{
    long long tot=0;
    int cur_min_price, cur_distance;
    cur_min_price=P[0]; cur_distance=D[0];
    for(int i=1;i<N-1;i++){
        if(cur_min_price > P[i]){
            tot+=(long long)cur_min_price*cur_distance;
            cur_min_price=P[i]; cur_distance=D[i];
        }else{
            cur_distance+=D[i];
        }
    }
    tot+=(long long)cur_min_price*cur_distance;
    return tot;
}

int main()
{
    inputData();
    cout << solve() << "\n";
    return 0;
}
