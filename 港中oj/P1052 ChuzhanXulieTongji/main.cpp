#include <iostream>

using namespace std;

int n;
int istack, rem;
int cnt = 0;

void sol(int i)//x�׶ν���i���� i==0��ջ i==1��ջ
{
    if(i == 1)
    {
        if(rem == 0){cnt++; return;}
        if(istack == 0)return ;
        istack --;
        sol(0);
        sol(1);
        istack ++;
        return;
    }
    else
    {
        if(rem == 0)return ;
        rem --;
        istack ++;
        sol(0);sol(1);
        rem++;
        istack --;
        return ;
    }
}
int main()
{
    cin >> n;
    istack = 0;
    rem = n;
    sol(0);
    cout<<cnt << endl;
    return 0;
}
