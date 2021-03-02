#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define MAX (5)
#define MAXN (10)

int C;
char MAP[MAX][MAX+1];
int N;
char WORD[MAXN][MAXN+1];

int MEMO[10][MAX][MAX];

int dy[]={-1,-1,-1,0,1,1,1,0};
int dx[]={-1,0,1,1,1,0,-1,-1};

void inputData()
{
    for(int i=0;i<MAX;i++){
        scanf("%s",MAP[i]);
    }

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",WORD[i]);
    }
}

int DFS(int y, int x,const char* word,int idx)
{
    int ny,nx;

    if(word[idx]!=MAP[y][x]) return MEMO[idx][y][x]=0;
    if((int)(strlen(word)-1)==idx){ return MEMO[idx][y][x]=1;}

    if(MEMO[idx][y][x]!=-1) return MEMO[idx][y][x];

    for(int i=0;i<8;i++){
        ny=y+dy[i]; nx=x+dx[i];
        if(ny<0||ny>=MAX||nx<0||nx>=MAX) continue;
        if((MEMO[idx][y][x]=DFS(ny,nx,word,idx+1))) return 1;
    }
    return MEMO[idx][y][x];
}

bool hasWord(const char* word)
{
    for(int y=0;y<MAX;y++){
        for(int x=0;x<MAX;x++){
            if(DFS(y,x,word,0)) return true;
        }
    }
    return false;
}

void initMEMO()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<MAX;j++){
            for(int k=0;k<MAX;k++){
                MEMO[i][j][k]=-1;
            }
        }
    }
}

void solve()
{
    bool ans;
    for(int i=0;i<N;i++){
        initMEMO();
        ans = hasWord(WORD[i]);
        printf("%s ",WORD[i]);
        if(ans){
            printf("%s\n","YES");
        }else{
            printf("%s\n","NO");
        }
    }
}

int main()
{
    scanf("%d",&C);
    for(int i=0;i<C;i++){
        inputData();
        solve();
    }
}
