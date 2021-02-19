#include <iostream>
using namespace std;

#define MAX (20)
int DP[MAX+10][MAX+10][MAX+10];
int a,b,c;

void inputData(){
    cin >> a >> b >> c;
}

int w(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20) return w(20,20,20);

    if(DP[a][b][c]!=0) return DP[a][b][c];

    if(a<b && b<c){
        DP[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }else{
        DP[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
    return DP[a][b][c];
}

void solve()
{
    int res;
    res = w(a,b,c);
    cout << "w(" << a << ", " << b << ", " << c << ")" << " = " << res << endl;
}

int main()
{
    while(true){
        inputData();
        if(a==-1 && b==-1 && c==-1) break;
        solve();
    }
    return 0;
}
