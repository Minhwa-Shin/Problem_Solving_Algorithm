#include <iostream>
using namespace std;

#define MAX ((int)1e5)
int N;
int wp=0;
int QUE[MAX+10];

int Enque(int d)
{
    if(wp==MAX-1) return 0;
    QUE[++wp]=d;
    int c=wp,p=c/2;
    while(p>0){
        if(QUE[c]>QUE[p]){
            swap(QUE[c],QUE[p]);
            c=p; p=c/2;
        }else break;
    }
    return 1;
}

int Deque()
{
    if(wp==0) return 0;
    int ret=QUE[1];
    QUE[1]=QUE[wp--];
    int c,p=1,L=2,R=3;
    while(L<=wp){
        if(R>wp) c=L;
        else c=(QUE[L]>QUE[R])?L:R;
        if(QUE[c]>QUE[p]){
            swap(QUE[c],QUE[p]);
            p=c; L=2*p; R=L+1;
        }else break;
    }
    return ret;
}

int main()
{
    int cmd;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&cmd);
        if(cmd==0){
            printf("%d\n",Deque());
        }else{
            Enque(cmd);
        }
    }
    return 0;
}
