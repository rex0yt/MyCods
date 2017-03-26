#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a;
vector <int> cnt(10);


void input()
{
    cin >> a;
    return ;
}

void countNum()
{
    for(int i = 0; i < (int)a.length(); i ++)
    {
        cnt[a[i] - '0'] ++;
    }
    return ;
}
void output()
{
    for(int i = 0; i < 10; i ++)
    {
        if(cnt[i] != 0)
        {
            cout << i << ":" << cnt[i] << endl;
        }
    }
    return ;
}
int main()
{
    input();
    countNum();
    output();

    return 0;
}
