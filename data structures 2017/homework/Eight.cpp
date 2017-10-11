/*
*Eight Queens
*rex0yt
*2017/10/10 15:10
*/
#include <bits/stdc++.h>
using namespace std;

bool chessboard[9][9];
int cntAns = 0;

bool Check(int row, int col)//check if the position is ok
{
    //check the range of col and row
    if(row>8 || row<1)return false;//row out of range
    if(col>8 || col<1)return false;//col out of range

    //check points in straight line
    for(int i=1; i<=8; i++)
    {
        if(chessboard[i][col] == false)//in one column
            return false;
        if(chessboard[row][i] == false)//in one row
            return false;
    }

    //check points in diagonal line
    for(int i=1; i<=8&&row+i<=8&&col+i<=8; i++)//right down
    {
        if(chessboard[row+i][col+i] == false)
            return false;
    }
    for(int i=1; i<=8&&row-i>=1&&col-i>=1; i++)//left up
    {
        if(chessboard[row-i][col-i] == false)
            return false;
    }
    for(int i=1; i<=8; i++)//left down and right up
    {
        int newcol = row+col-i;//col + row == newcol + newrow
        if(newcol<1 || newcol >8)continue;
        if(chessboard[i][newcol] == false)
            return false;
    }
    return true;
}

bool Init()//make each position leagle
{
    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            chessboard[i][j] = true;
    return true;
}

void PrintAns()//print one solution
{
    cout << "Solution" << cntAns+1 << ":" << endl;

    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            cout << chessboard[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cntAns ++;//count each solution
    return ;
}

void Solve(int LayerRow = 8)//to solve
{
    if(LayerRow == 0)//get one solution
    {
        PrintAns();//print this solution
        return ;
    }
    for(int i=1; i<=8; i++)//try all 8 positions in one row
    {
        if(Check(LayerRow, i))//the position is leagle
        {
            chessboard[LayerRow][i] = false;//mark
            Solve(LayerRow-1);//try next row
            chessboard[LayerRow][i] = true;//unmark
        }
    }
    return ;
}

int main()
{
    Init();
    Solve();
    return 0;
}
