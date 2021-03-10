#include <iostream>
#include <utility>
#include <stack>
using namespace std;

#define MAXN ((int)5e5)
int N;
int T[MAXN+10];

void inputData()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> T[i];
    }
}

void solve()
{
    stack<pair<int,int>> stk;
    for(int i=1;i<=N;i++){
        while(!stk.empty() && stk.top().second < T[i])
        {
            stk.pop();
        }

        if(!stk.empty()){
            cout << stk.top().first << " ";
            if(stk.top().second==T[i]) stk.pop();
        }else{
            cout << 0 << " ";
        }

        stk.push(make_pair(i,T[i]));
    }
}

int main()
{
    inputData();
    solve();
    return 0;
}
