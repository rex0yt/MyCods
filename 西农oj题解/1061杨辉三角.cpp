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
#define MaxN (100)

// using std::ios;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
using namespace std;

long long arr[MaxN][MaxN];

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

void init()
{
    for(int i=1; i<MaxN; i++)
    {
        arr[i][1] = arr[i][i] = 1;
        for(int j=2; j<i; j++)
        {
            arr[i][j] = arr[i-1][j]+ arr[i-1][j-1];
        }
    }
}

int main()
{
    initProgram();
    init();

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << arr[i][i] << "\n";
//        cout << "\n";
    }
    return 0;
}
