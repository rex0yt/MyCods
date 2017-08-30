#include <iostream>
#include <string.h>

#define N 15+5

using namespace std;

int pa_x,pa_y,pb_x,pb_y,pm_x,pm_y;
int imap[N][N];

int dir_x[] = {1,-1,2,-2,1,-1,2,-2};
int dir_y[] = {2,2,1,1,-2,-2,-1,-1};

int cnt = 0;

void init()
{
    int newx,newy;

    pa_x = pa_y = 0;
    cin >> pb_x >> pb_y >> pm_x >> pm_y;
    memset(imap,0,sizeof(imap));
    imap[pm_x][pm_y] = 1;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            newx = pm_x + dir_x[i];
            newy = pm_y + dir_y[i];
            imap[newx][newy] = 1;
        }
    }
}

void sol(int x, int y)
{
    if((x<pa_x || x>pb_x)||(y<pa_y || y>pb_y))
        return ;
    if(imap[x][y] == 1)return ;
    if(x==pb_x && y==pb_y)
    {
        cnt ++;
        return;
    }
    sol(x+1,y);
    sol(x,y+1);
}

int main()
{
    init();
    sol(0,0);
    cout << cnt << endl;
    return 0;
}
