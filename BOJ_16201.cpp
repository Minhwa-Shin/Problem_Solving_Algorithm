#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define MOD (1000000007)

int R,C,K;
vector<pair<int,int>> T; //부서지지 않은 타일 위치(행,열)

void inputData()
{
    int y,x;
    cin >> R >> C >> K;
    for(int i=0;i<K;i++){
        cin >> y >> x;
        T.push_back(make_pair(y,x));
    }
}

bool cmp(const pair<int,int>& A,const pair<int,int>& B)
{
    if(A.first!=B.first) return A.first < B.first;
    return A.second < B.second;
}

long long Count(const vector<pair<int,int>>& R)
{
    long long cnt=0;
    for(auto r:R){
        if((r.second-r.first+1)>(long long)1)
            cnt+=((long long)r.second-r.first+1)/2;
    }
    return cnt;
}

long long Case(const vector<pair<int,int>>& R)
{
    long long numCase=1;
    for(auto r:R){
        long long len=(long long)r.second-r.first+1;
        if((len>1) && (len%2==1))
        {
            numCase = (numCase%MOD * (len/2+1)%MOD)%MOD;
        }
    }
    return numCase;
}

int powMod(long long x,long long y,int p)
{
    int res=1;
    x=x%p;
    while(y>0){
        if(y&1){
            res=(res*x)%p;
        }
        y>>=1;
        x=(x*x)%p;
    }
    return res;
}

void solve()
{
    long long totalCnt=0,total_case=1,numCase;
    int t_row_cnt=0;

    //1.부서지지 않은 타일 위치 오름차순 정렬
    sort(T.begin(),T.end(),cmp);

    //3. 부서지지 않은 타일이 없으면 결과를 계산하여 출력
    if(T.empty()){
        if(C%2==0){
            cout << ((long long)C/2)*R << " " << 1 << "\n";
        }else{
            /*for(int i=0;i<R-t_row_cnt;i++){
                total_case=(total_case%MOD * ((long long)C/2+1)%MOD)%MOD;
            }*/
            total_case=total_case * powMod((long long)C/2+1,(long long)R-t_row_cnt,MOD);
            cout << ((long long)C/2)*R << " " << total_case << "\n";
        }
        return;
    }

    //3. 각 행별로 구간을 나누고, 계산
    vector<pair<int,int>> Row;
    t_row_cnt=1;
    pair<int,int> P;
    int current_R=T[0].first;
    Row.push_back({1,T[0].second-1}); Row.push_back({T[0].second+1,C});
    for(int i=1;i<K;i++){
        if(T[i].first==current_R){ //현재 행
            P=Row.back();
            Row.back()={P.first,T[i].second-1};

            Row.push_back({T[i].second+1,P.second});

        }else{ //새로운 행
            t_row_cnt++;
            totalCnt+=Count(Row);

            numCase=Case(Row);
            total_case = ((total_case%MOD) * numCase%MOD)%MOD;

            Row.clear();
            current_R=T[i].first;
            Row.push_back({1,T[i].second-1}); Row.push_back({T[i].second+1,C});
        }
    }

    if(Row.size()>0){
        totalCnt+=Count(Row);

        numCase=Case(Row);
        total_case = ((total_case%MOD) * numCase%MOD)%MOD;
    }

    totalCnt+=(((long long)C/2)*((long long)R-t_row_cnt));
    if(C%2==1){
        /*for(int i=0;i<R-t_row_cnt;i++){
            total_case=(total_case%MOD * ((long long)C/2+1)%MOD)%MOD;
        }*/
        total_case=(total_case*powMod((long long)C/2+1,(long long)R-t_row_cnt,MOD))%MOD;
    }

    cout << totalCnt << " " << total_case << "\n";
}

int main()
{
    inputData();
    solve();
    return 0;
}
