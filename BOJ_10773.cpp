#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int K;

int solve()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> K;

    stack<int> stk;
    int num, total=0;
    for(int i=0;i<K;++i){
        cin >> num;
        if(num==0 && !stk.empty()){
            total-=stk.top(); stk.pop();
        }else{
            total+=num; stk.push(num);
        }
    }
    return total;
}

int main()
{
    cout << solve() << "\n";
}
