using namespace std;

#include <bits/stdc++.h>
#define MaxN 100

bool chessboard[MaxN][MaxN];
int n = 5;//待排列的个数
int cntAns = 0;//统计答案个数

bool Check(int row, int col)//位置的合法性检查
{
    //检查行列是否越界
    if(row>n || row<1)return false;//行的范围
    if(col>n || col<1)return false;//列的范围

    //检查同一行或列上是否攻击
    for(int i=1; i<=n; i++)
    {
        if(chessboard[i][col] == false)//在同一列上有
            return false;
        if(chessboard[row][i] == false)//在同一行上有
            return false;
    }
    return true;//合法，返回可行
}

bool Init()//将所有点设置为没有放置棋子
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            chessboard[i][j] = true;
    return true;
}

void PrintAns()//打印答案
{
    cout << "Solution" << cntAns+1 << ":" << endl;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(chessboard[i][j] == 0)//如果放置，输出位置
            {
                cout << j;
                break;
            }
        }
    }
    cout << endl;

    cntAns ++;//统计答案个数
    return ;
}

void Solve(int LayerRow = 1)//递归求解函数
{
    if(LayerRow == n+1)//递归达到最底层，得到一个解
    {
        PrintAns();//打印答案
        return ;
    }
    for(int i=1; i<=n; i++)//尝试一行里所有的N个点
    {
        if(Check(LayerRow, i))//检查该点的合法性
        {
            chessboard[LayerRow][i] = false;//标记
            Solve(LayerRow+1);//尝试下一层
            chessboard[LayerRow][i] = true;//取消标记
        }
    }
    return ;
}

int main()
{
    cin >> n;//输入全排列的个数

    Init();//初始化程序
    Solve();//递归求解问题 包含答案输出

    return 0;
}
