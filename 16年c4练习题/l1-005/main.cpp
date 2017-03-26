#include <iostream>

using namespace std;

const int N = 1000 + 10;

long long a[N];
short b[N], c[N];

int m, n;

void input()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    return ;
}
int findN(int _b)
{
    for(int i = 0; i < n; i ++)
    {
        if(b[i] == _b)return i;
    }
}
void output(int i)
{
    cout << a[i] << " " << c[i] << endl;
    return ;
}
void calc()
{
    int tmp;

    cin >> m;
    while(m --)
    {
        cin >> tmp;
        output(findN(tmp));
    }
}
int main()
{
    input();
    calc();
    return 0;
}
