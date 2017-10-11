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

int yinzihe(int i)
{
    if(i == 1)return 1;
    if(i == 2)return 3;
    int ans = 1;
    for(int j=2; j<=int(sqrt(i)); j++)
    {
        if(i%j == 0)
        {
            ans += j;
            if(i/j != j)
                ans += i/j;
        }
    }
    return ans;
}

int main()
{
    initProgram();
    int ans;
//    因子不包括本身，包括1

//    for(int i=1; i<6; i++)
//        cout<<yinzihe(i) << " ";
    for(int i=2; i<=10000; i++)
    {
        ans = yinzihe(i);
        if(ans > 10000)continue;
        if(yinzihe(ans) == i && ans > i)
            cout<<i<<" "<<ans<<"\n";
    }

    return 0;
}
