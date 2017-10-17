using namespace std;

#include <bits/stdc++.h>
#define MaxN 100

bool chessboard[MaxN][MaxN];
int n = 5;  //可选择的个数
int r = 3;  //需要选择的个数
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

//下次层递归得到的数字比上一行大，保证结果不重复
//minval：上一层的数字，这层要比上一层大
//LayerRow：递归层次，[1, n]，大于n输出答案
void Solve(int minval, int LayerRow = 1)//递归求解函数
{
    if(LayerRow == r+1)//递归达到最底层，得到一个解
    {
        PrintAns();//打印答案
        return ;
    }
    if(minval+1 > n)return ;//递归到该层，超出范围，无解
    for(int i=minval+1; i<=n; i++)//尝试一行里所有大于minval的点
    {
        if(Check(LayerRow, i))//检查该点的合法性
        {
            chessboard[LayerRow][i] = false;//标记
            Solve(i, LayerRow+1);//尝试下一层
            chessboard[LayerRow][i] = true;//取消标记
        }
    }
    return ;
}

int main()
{
    cin >> n >> r;//输入组合的个数

    Init();//初始化程序
    Solve(0, 1);//递归求解问题 包含答案输出

    return 0;
}
