#include <iostream>
using namespace std;

#define MAXN ((int)1e5)
int K;
int sp=0;
int stk[MAXN+10];

void push(int n){stk[++sp]=n;};
bool empty(){return sp==0;}
int size(){return sp;}
int top(){
    if(!empty()) return stk[sp];
    return -1;
}
void pop(){--sp;}

int main()
{
    int n;
    cin >> K;
    for(int i=0;i<K;i++){
        cin >> n;
        if(n!=0) push(n);
        else pop();
    }

    int sum=0;
    while(!empty()){
        sum+=top(); pop();
    }
    printf("%d",sum);

    return 0;
}
