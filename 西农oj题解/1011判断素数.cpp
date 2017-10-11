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


// #define LOCAL
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
    // cin.tie(0);
    #endif // CPPIO

    return ;
}

int main()
{
    initProgram();
    int n;
    cin >> n;
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
        {
            cout<<"No"<<endl;
            return 0;
        }

    }
    cout<<"Yes"<<endl;
    return 0;
}
