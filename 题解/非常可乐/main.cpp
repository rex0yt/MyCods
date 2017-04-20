#include <bits/stdc++.h>

using namespace std;

#define N 100 + 10

struct Node
{
    int arr[3];/*cola cup1 cup2*/
    int level;
} tmp;


bool imap[N][N];
int a[3];

bool pour(int i, int j)
{
    if(tmp.arr[i] <= a[j] - tmp.arr[j])//i empty
    {
        tmp.arr[j] += tmp.arr[i];
        tmp.arr[i] = 0;
    }
    else                            //j full
    {
        tmp.arr[i] -= a[j] - tmp.arr[j];
        tmp.arr[j] = a[j];
    }
    if(imap[tmp.arr[1]][tmp.arr[2]] == 0)//状态没有出现过
    {
        imap[tmp.arr[1]][tmp.arr[2]] = 1;
        return 1;
    }
    return 0;
}

void bfs()
{
    queue <Node> sol;
    tmp.arr[0] = a[0];
    tmp.arr[1] = tmp.arr[2] = tmp.level = 0;
    sol.push(tmp);
    imap[0][0] = 1;
    while(! sol.empty())
    {
        for(int i=0; i<=2; i ++)
            for(int j=0; j<=2; j++)
            {
                if(i == j)continue;
                tmp = sol.front();
                tmp.level ++;
                if(pour(i, j))
                {
                    if(2*tmp.arr[0]==a[0])
                    {
                        if(2*tmp.arr[1]==a[0]||2*tmp.arr[2]==a[0])
                        {
                            cout << tmp.level << endl;
                            return ;
                        }
                    }
                    else
                    {
                        sol.push(tmp);
                    }
                }
            }
        sol.pop();
    }
    cout << "NO" << endl;
    return ;
}

int main()
{
    while((cin >> a[0] >> a[1] >> a[2]) && (a[0] || a[1] || a[2]))
    {
        memset(imap, 0,sizeof(imap));
        bfs();
    }
    return 0;
}
