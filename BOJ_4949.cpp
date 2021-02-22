#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

#define MAX (100)

int N;
char str[MAX+10];

string msg[]={"no","yes"};

int isVPS()
{
    stack<char> stk;
    for(int i=0;str[i];i++){
        if(str[i]=='('||str[i]=='['){
            stk.push(str[i]);
        }else if(str[i]==')'){
            if(stk.empty()) return 0;
            if(stk.top()=='(') stk.pop();
            else return 0;
        }else if(str[i]==']'){
            if(stk.empty()) return 0;
            if(stk.top()=='[') stk.pop();
            else return 0;
        }
    }

    if(stk.empty()) return 1;
    else return 0;
}

int main()
{
    while(true){
       cin.getline(str,110);
       if(strcmp(str,".")==0)break;
       cout << msg[isVPS()] << endl;
    }
    return 0;
}
