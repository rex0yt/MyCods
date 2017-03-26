#include <iostream>

using namespace std;

const int N = 100;

struct Point
{
    int row;
    int col;
    int pre;
};

int map[N][N];
Point sol[N*N];

int map_row, map_col, new_row, new_col;
int pnt, top;
int dir_row[8]= {-1,-1,-1, 0, 0, 1, 1, 1}; /*搜索方向*/
int dir_col[8]= {-1, 0, 1,-1, 1,-1, 0, 1};

void push(int p_row,int p_col)
{
    top ++;
    sol[top].row = p_row;
    sol[top].col = p_col;
    sol[top].pre = pnt;

    return ;
}

bool canGo(int row, int col)
{
    if(map[row][col] == 0)return true;
    return false;
}

void createmap()
{
    cin >> map_row >> map_col;
    //设置地图边界
    for(int i = 0; i <= map_col+1; i ++)
        map[0][i]=map[map_row+1][i]=1;
    for(int i = 0; i <= map_row + 1 ; i ++)
        map[i][0]=map[i][map_col+1]=1;
    //读取地图
    for(int i = 1; i <= map_row; i ++)
        for(int j = 1; j <= map_col; j ++)
            cin >> map[i][j];
}

void bfs()
{
    pnt = 0;
    top = 0;
    while((sol[top].row!=map_row)||(sol[top].col!=map_col))
    {
        for(int i = 0; i < 8; i ++)
        {
            new_row = sol[pnt].row + dir_row[i];
            new_col = sol[pnt].col + dir_col[i];
            if(canGo(new_row, new_col)) //路可以走
            {
                push(new_row, new_col);
                map[new_row][new_col] ++;
            }
        }
        pnt ++;
    }
}

void printRes()
{
    int p1 = top;
    while(0 != p1)
    {
        cout << "(" << sol[p1].row << ',' << sol[p1].col << ")" << endl;
        p1 = sol[p1].pre;
    }
    cout << "(1,1)";
}

int main()
{
    createmap();

    sol[0].row = 1;//初始化栈
    sol[0].col = 1;
    sol[0].pre = -1;
    map[1][1] ++;//防止重复访问初始结点

    bfs();
    printRes();

    return 0;
}
