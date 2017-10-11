#include <bits/stdc++.h>
using namespace std;

void TenToTwo(int toChange)//change
{
    if(toChange == 0)
    {
        return ;
    }
    TenToTwo(toChange/2);
    cout << toChange%2;
}

int main()
{
    int toChange;
    cin >> toChange;
    TenToTwo(toChange);

    return 0;
}
