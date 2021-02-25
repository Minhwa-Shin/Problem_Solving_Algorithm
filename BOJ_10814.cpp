#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAXN ((int)1e5)

struct MEMBER{
    int id;
    int age;
    string name;
};

int N;
MEMBER M[MAXN+10];

void inputData()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++){
        M[i].id=i;
        cin >> M[i].age >> M[i].name;
    }
}

bool cmp(const MEMBER& A, const MEMBER& B)
{
    if(A.age!=B.age) return A.age < B.age;
    return A.id < B.id;
}

void solve()
{
    sort(begin(M),begin(M)+N,cmp);
    for(int i=0;i<N;i++){
        cout << M[i].age << " " << M[i].name << "\n";
    }
}

int main()
{
    inputData();
    solve();
    return 0;
}
