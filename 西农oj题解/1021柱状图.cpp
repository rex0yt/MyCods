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
#include <cstring>


//#define LOCAL
//#define CPPIO
#define MaxN (100000)

// using std::ios;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
using namespace std;


void initProgram()
{
    #ifdef LOCAL
    freopen("data.txt","r",stdin);
    #endif // LOCAL

    #ifdef CPPIO
    ios::sync_with_stdio(false);
//    cin.tie(0);
    #endif // CPPIO

    return ;
}

int main()
{
    initProgram();

    char tmp[MaxN];
    int cnt[30];
    memset(cnt,0,sizeof(cnt));

    for(int i=0; i<4; i++)
    {
        gets(tmp);
        int length = strlen(tmp);
        for(int j=0; j<length; j++)
        {
            if('A' <= tmp[j] && tmp[j] <= 'Z')
            {
                cnt[tmp[j]-'A'] ++;
            }
        }
    }

    int imax = 0;
    while(true)
    {

        imax = 0;
        for(int i=0; i<26; i++)
        {
            if(cnt[imax] <= cnt[i])imax = i;
        }
        if(cnt[imax] == 0)break;
        for(int i=0; i<imax; i++)
        {
            if(cnt[i] == cnt[imax])
            {
                cout<<"*";
                cnt[i]--;
            }
            else
            {
                cout<<" ";
            }
            cout<<" ";
        }
        cnt[imax]--;
        cout<<"*\n";
    }
    for(int i=0; i<26; i++)
    {
        cout << (char)('A'+i) << " ";
    }
    cout << "\n";
    return 0;
}
