#include <iostream>

using namespace std;

const int NN = 5000 + 10;

int father[NN];
int ranki[NN] = {0};

int find(int x)
{
    if(x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

void unioni(int x, int y)
{
    int r1 = find(x);
    int r2 = find(y);
    if(r1 == r2)return ;
    if(ranki[r1] < ranki[r2])
        father[r2] = r1;
    else{
        if(ranki[r1] < ranki[r2])
            ranki[r2] ++;
        father[r1] = r2;
    }
}
int main()
{
    int m, n, p;
    int tmp1, tmp2;
    cin >> n >> m >> p;
    for(int i = 0; i <= n;i ++)
        father[i] = i;
    while(m --)
    {
        cin >> tmp1 >> tmp2;
        unioni(tmp1, tmp2);
    }
    while(p --)
    {
        cin >> tmp1 >> tmp2;
        if(find(tmp1) == find(tmp2))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
