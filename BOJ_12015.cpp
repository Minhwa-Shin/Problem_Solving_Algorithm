#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define MAXN ((int)1e6)
int N;
vector<int> A(MAXN+10,0);
vector<int> LIS;

void inputData()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
}

int solve()
{
    LIS.push_back(A[0]);
    for(int i=1;i<N;i++)
    {
        if(LIS.back()<A[i]) LIS.push_back(A[i]);
        else{
            auto it=lower_bound(begin(LIS),end(LIS),A[i]);
            *it=A[i];
        }
    }
    return LIS.size();
}

int main()
{
    inputData();
    cout << solve() << "\n";
    return 0;
}
