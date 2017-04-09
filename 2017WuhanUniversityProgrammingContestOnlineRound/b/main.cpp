#include <iostream>

using namespace std;

const int modd = 1e7 + 9;

int main()
{
    int m, n;
    int x, y;
    int cnt;
    long long ans;
    int tmp;
    while(cin >> n >> m)
    {
        for(int i = 0; i < n-1; i ++)
            cin >> x >> y;
        ans = 1;
        for(int i = 0; i < n; i ++)
        {
            cnt = 0;
            for(int j = 0; j < m; j ++)
            {
                cin >> tmp;
                if(tmp)cnt ++;
            }
            if(i == 0)
            {
                ans *= cnt;
            }
            else
            {
                ans *= cnt - 1;
            }
            ans %= modd;
        }
        cout << ans << endl;
    }
    return 0;
}
