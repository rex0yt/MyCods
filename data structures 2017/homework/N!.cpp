#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100;

int flag[MaxN];


void init()
{
    for(int i=0; i<MaxN; i++)
    {
        flag[i] = 0;    //0 available
    }
    return ;
}

void PaiLie(int sizeOfPailie, int mark)
{
    if(mark == 0)
    {
        for(int i=1; i<=sizeOfPailie; i++)
        {
            for(int j=1; j<=sizeOfPailie; j++)
            {
                if(flag[j] == i)cout <<j <<" ";
            }
//            if(flag[i] == i)cout <<i <<" ";
        }
        cout <<endl;
        return ;
    }

    for(int i=1; i<=sizeOfPailie; i++)
    {
        if(flag[i] == 0) // i haven't been used
        {
//            cout <<i <<" ";
            flag[i] = sizeOfPailie+1-mark;
            PaiLie(sizeOfPailie, mark-1);
            flag[i] = 0;
        }
    }
    return ;
}

int main()
{
//    freopen("data.txt", "w", stdout);
//    ios::sync_with_stdio(false);

    int sizeOfPailie;
    cin >> sizeOfPailie;

    init();     //initial
    PaiLie(sizeOfPailie, sizeOfPailie);   //Pailie

    return 0;
}
