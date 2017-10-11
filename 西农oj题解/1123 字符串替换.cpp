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
#define CPPIO
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

int ainb(string &a,string &b)
{
//    返回a在b中第一次出现的位置，没有返回-1
    int lena = a.length();
    int lenb = b.length();
    if(lenb < lena)return -1;

    int flag = false;
    int loc;
    for(int i=0; i<=(lenb-lena) && !flag; i++)
    {
        loc = i;
        flag = true;
        for(int j=0; j<lena; j++)
        {
            if(b[i+j] != a[j])
            {
                flag = false;
                break;
            }
        }
    }
    if(flag)return loc;
    return -1;
}
int main()
{
    initProgram();

    string stra, strb, strc;
    cin >> stra >> strb >> strc;
    int ans = ainb(strb,stra);
    if(ans == -1)
        cout<<stra<<"\n";
    else
    {
        for(int i=0; i<ans; i++)
            cout<<stra[i];
        cout<<strc;
        for(int i=ans+strb.length(); i<stra.length(); i++)
            cout<<stra[i];
    }
//    string a("a");
//    string b("aa");
//
//    cout << ainb(a,b);
    return 0;
}
