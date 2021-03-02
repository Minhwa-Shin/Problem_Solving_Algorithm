#include <iostream>
#include <cstring>
using namespace std;

int C,n,m;
bool areFriends[10][10];

void inputData()
{
    int f1,f2;
    cin >> n >> m;

    memset(areFriends,0,sizeof(areFriends));
    for(int i=0;i<m;i++){
        cin >> f1 >> f2;
        areFriends[f1][f2]=areFriends[f2][f1]=true;
    }
}

int countFarings(bool taken[10])
{
    int firstFree=-1;
    for(int i=0;i<n;++i){
        if(!taken[i]){
            firstFree=i;
            break;
        }
    }

    if(firstFree==-1) return 1;

    int ret=0;

    for(int pairWith=firstFree+1;pairWith<n;++pairWith){
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree]=taken[pairWith]=true;
            ret+=countFarings(taken);
            taken[firstFree]=taken[pairWith]=false;
        }
    }
    return ret;
}

int solve()
{
    bool taken[10]={false,};
    return countFarings(taken);
}

int main()
{
    cin >> C;
    for(int c=0;c<C;++c){
        inputData();
        cout << solve() << "\n";
    }
    return 0;
}
