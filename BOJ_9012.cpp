#include <iostream>
#include <stack>
using namespace std;

#define MAX (50)

int N;
char str[MAX+10];

string msg[]={"NO","YES"};

void inputData()
{
    cin >> str;
}

/*int isVPS()
{
    int openCnt=0;
    for(int i=0;str[i];i++){
        if(str[i]=='(') openCnt++;
        else openCnt--;
        if(openCnt<0) return 0;
    }

    if(openCnt==0) return 1;
    else return 0;
}*/

int isVPS()
{
    stack<char> stk;
    for(int i=0;str[i];i++){
        if(str[i]=='(') stk.push(str[i]);
        else{
            if(stk.empty()) return 0;
            stk.pop();
        }
    }

    if(stk.empty()) return 1;
    else return 0;
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++){
        inputData();
        cout << msg[isVPS()] << endl;
    }
}
