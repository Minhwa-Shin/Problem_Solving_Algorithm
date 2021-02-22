#include <iostream>
#include <stack>
using namespace std;

#define MAXN ((int)1e5)
int N;
int A[MAXN+10];
char sol[MAXN*2+10];
int cnt=0;

void inputData()
{
    //cin >> N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        //cin >> A[i];
        scanf("%d",&A[i]);
    }
}

void printSOL()
{
    for(int i=0;i<cnt;i++){
        //cout << sol[i] << endl;
        printf("%c\n",sol[i]);
    }
}

int solve()
{
    int i,j;
    std::stack<int> stk;

    for(i=1,j=1;i<=N;i++){
        sol[cnt++]='+';
        stk.push(i);
        while(!stk.empty() && stk.top()==A[j]){
            //cout << stk.top() << " ";
            sol[cnt++]='-';
            stk.pop(); j++;
        }
    }

    /*while(j<=N && !stk.empty()){
        if(stk.top()==A[j]){
            //cout << stk.top() << " ";
            sol[cnt++]='-';
            stk.pop();
        }
        j++;
    }*/

    if(stk.empty()) return 1;
    else return 0;
}

int main()
{
    inputData();
    if(solve()){
        printSOL();
    }else{
        //cout << "NO" << endl;
        printf("%s\n","NO");
    }
    return 0;
}
