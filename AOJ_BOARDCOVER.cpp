#include <iostream>
using namespace std;

#define MAX (20)

int C,H,W;
char BOARD[MAX+2][MAX+2];

int Cnt=0;
int BLOCK[4][3][2]={{{0,0},{1,0},{0,1}},
                      {{0,0},{0,1},{1,1}},
                      {{0,0},{1,0},{1,1}},
                      {{0,0},{1,0},{1,-1}}};

void inputData()
{
    cin >> H >> W;
    for(int i=0;i<H;i++){
        cin >> BOARD[i];
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(BOARD[i][j]=='.') Cnt++;
        }
    }
}

void printBoard()
{
    cout <<"\n";
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << BOARD[i][j];
        }
        cout << "\n";
    }
}

bool setBoard(int y,int x,int idx,int delta)
{
    bool possible=true;
    int nY,nX;

    if(delta==1){
        for(int i=0;i<3;i++){
            nY=y+BLOCK[idx][i][0];
            nX=x+BLOCK[idx][i][1];

            if(nY<0||nY>=H||nX<0||nX>=W){
                possible=false; break;
            }

            if(BOARD[nY][nX]!='.'){
                possible=false; break;
            }
        }

        if(possible){
            for(int i=0;i<3;i++){
                nY=y+BLOCK[idx][i][0];
                nX=x+BLOCK[idx][i][1];
                BOARD[nY][nX]='#';
            }
        }
    }else{
        for(int i=0;i<3;i++){
            nY=y+BLOCK[idx][i][0];
            nX=x+BLOCK[idx][i][1];
            BOARD[nY][nX]='.';
        }
    }
    return possible;
}

int coverBoard()
{
    bool brk=false;
    int y,x;

    //printBoard();

    y=-1;x=-1;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(BOARD[i][j]=='.'){
                y=i;
                x=j;
                brk=true;
                break;
            }
        }
        if(brk) break;
    }

    if(y==-1) return 1;
    int ret=0;
    for(int i=0;i<4;++i){
        if(setBoard(y,x,i,1)){
            ret+=coverBoard();
            setBoard(y,x,i,-1);
        }
    }
    return ret;
}

void solve()
{
    cout << coverBoard() << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> C;
    for(int c=0;c<C;c++){
        inputData();
        solve();
    }
    return 0;
}
