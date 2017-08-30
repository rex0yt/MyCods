#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>

//#define LOCAL
#define CPPIO
#define MaxN 1000 + 100

using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void initProgram()
{
    #ifdef LOCAL
    freopen("data.txt","r",stdin);
    #endif // LOCAL

    #ifdef CPPIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    #endif // CPPIO

    return ;
}

string a,b;
string ans,tmp;

int lena,lenb;
int maxlen,minlen;

int main()
{
    initProgram();
    int n;
    cin >> n;
    int cnt = 0;
    while(cnt++ < n)
    {
        cin >> a >> b;
//      112233445566778899
//              9988776655
        lena = a.length();
        lenb = b.length();
        if(lenb < lena)
        {
            ans = a;
            tmp = b;
            maxlen = lena;
            minlen = lenb;
        }
        else
        {
            ans = b;
            tmp = a;
            maxlen = lenb;
            minlen = lena;
        }
        for(int i=minlen-1,j=maxlen-1; i>=0; i--,j--)
        {
            ans[j] += tmp[i]-'0';
        }
        bool flag = false;//长度加一标记
        for(int i=maxlen-1; i>0; i--)
        {
            if(ans[i] > 9+'0')
            {
                ans[i] = (ans[i]-'0')%10 + '0';
                ans[i-1] ++;
            }
        }
        if(ans[0] > 9+'0')
        {
            ans[0] = (ans[0]-'0')%10 + '0';
            flag = true;
        }
        cout << "Case " << cnt << ":" << endl;
        cout << a << " + " << b << " = ";
        if(flag)cout<<1;
        cout<<ans<<endl;
        if(cnt < n)cout << endl;
    }
    return 0;
}
