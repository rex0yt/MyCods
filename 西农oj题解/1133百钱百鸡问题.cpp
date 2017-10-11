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

int main()
{
    initProgram();

    for(int i=0; i<=40; i++)
        for(int j=0; j<60; j++)
    {
        int rem = 100 - 3*i - 2*j;
        if(rem < 0)break;
        if(i+j+3*rem == 100)
            cout << i << " " << j << " " << rem*3 <<"\n";
    }
    return 0;
}
