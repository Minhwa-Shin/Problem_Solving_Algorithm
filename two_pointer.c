#include <stdio.h>
#include <stdlib.h>
 
int N, d, k, c; //N:회전 초밥 벨트에 놓인 접시의 수
                //d:초밥의 가짓수
                //k:연속해서 먹는 접시의 수
                //c:쿠폰 번호
 
int a[30000+10];
int Cnt[3000+10];
int maxCnt=-1;
 
void inputData()
{
    int i;
 
    scanf("%d %d %d %d", &N, &d, &k, &c);
    for(i=0 ; i<N ; i++)
    {
        scanf("%d", &a[i]);
    }
}
 
int Max(int a,int b)
{
   if(a<b)  return b;
   else return a;
}
 
void solve()
{
    int i,j,cnt,dish;
 
    cnt=0; dish=0;
    for(i=0,j=0;i<N;i++){
        while(dish<k){
            if(Cnt[a[j]]++==0) ++cnt;
            dish++;
            j=(j+1)%N;
        }
 
        if(Cnt[c]==0){
            maxCnt=Max(maxCnt,cnt+1);
        }else{
            maxCnt=Max(maxCnt,cnt);
        }
 
        if(--Cnt[a[i]]==0) --cnt;
        dish--;
    }
}
 
int main(void)
{
    inputData();
    solve();
    printf("%d", maxCnt);
    return 0;
}
