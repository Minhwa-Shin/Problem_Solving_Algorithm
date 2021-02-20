#include <iostream>
using namespace std;

#define MAXN ((int)1e4)
int Check[MAXN+2];

void d(int n)
{
    if(n>MAXN) return;
    int num=n;
    int res=n;
    while(num>0){
        res+=num%10; num/=10;
    }
    Check[res]=1;
    d(res);
}

void printSelfNumber()
{
    for(int i=1;i<=MAXN;i++){
        if(Check[i]==0){
            printf("%d\n",i);
        }
    }
}

int main()
{
    for(int i=1;i<=MAXN;i++){
        if(Check[i]==0){
            d(i);
        }
    }
    printSelfNumber();
    return 0;
}
