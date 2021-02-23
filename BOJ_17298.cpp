#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> L_stk;
stack<int> R_stk;
stack<int> sol;

void inputData()
{
    int n;
    scanf("%d",&N); //cin >> N;
    for(int i=0;i<N;i++){
        scanf("%d",&n); //cin >> n;
        L_stk.push(n);
    }
}

void solve()
{
    int n;
    while(!L_stk.empty()){
        n=L_stk.top(); L_stk.pop();

        while(!R_stk.empty() && R_stk.top()<=n){
            R_stk.pop();
        }
        if(!R_stk.empty()){
            sol.push(R_stk.top());//cout << R_stk.top() << " ";
        }else{
            sol.push(-1); //cout << -1 << " ";
        }

        R_stk.push(n);
    }

    while(!sol.empty()){
        printf("%d ",sol.top()); sol.pop();//cout << sol.top() << " "; sol.pop();
    }
    printf("\n");//cout << endl;
}

int main()
{
    inputData();
    solve();
    return 0;
}
