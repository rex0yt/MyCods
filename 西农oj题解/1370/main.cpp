#include <iostream>

using namespace std;

const int  N = 1000;

struct Node
{
    int row;
    int col;
    int dir;/*搜索方向*/
};

struct Point
{
    int row;
    int col;
};

int map[N][N];
Node sol[N*N];
Point poi, mapIn, mapOut;
int row, col;
int top;

Point dir[4]= {{1,0},{0,-1},{-1,0},{0,1}}; /* 下 左 上 右*/

void push(int p_row,int p_col)
{
    top ++;
    sol[top].row = p_row;
    sol[top].col = p_col;
    sol[top].dir = 0;
    map[p_row][p_col] ++;
}

void pop()
{
    top --;
    return ;
}

bool canGo(int prow, int pcol){
    if(prow < 0 || pcol < 0)return false;
    else if(0 == map[prow][pcol])return true;
    return false;
}

void createMap()
{
    cin >> col >> row;
    for(int i = 0; i < row; i ++)
        for(int j=0; j < col; j ++)
        {
            cin >> map[i][j];
            //记录入口
            if(map[i][j] == 3)
            {
                mapIn.row = i;
                mapIn.col = j;
                map[i][j] = 0;
            }//记录出口
            else if(map[i][j] == 4)
            {
                mapOut.row = i;
                mapOut.col = j;
                map[i][j] = 0;
            }
        }
}

void dfs(){
    top = 0;
    sol[top].row = mapIn.row;
    sol[top].col = mapIn.col;
    sol[top].dir = 0;
    map[mapIn.row][mapIn.col] = 1;

    while(sol[top].row != mapOut.row || sol[top].col != mapOut.col)
    {
        if(sol[top].dir <= 3)
        {
            poi.row = sol[top].row + dir[sol[top].dir].row;
            poi.col = sol[top].col + dir[sol[top].dir].col;
            sol[top].dir ++;
            if(canGo(poi.row, poi.col))
                push(poi.row, poi.col);
        }
        else{
            pop();
        }
    }
}

void printRes()
{
    for(int i = 0; i <= top; i ++)
        cout << sol[i].col << " " << sol[i].row << endl;
}

int main()
{
    createMap();
    dfs();
    printRes();
    return 0;
}
