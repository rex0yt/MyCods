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
    string tmp;
    cin >> tmp;
    int len = tmp.length();
    for(int i=0; i<len; i++)
    {
        if('a' <= tmp[i] && tmp[i] <= 'z')
            tmp[i] += 'A'-'a';
        else if('A' <= tmp[i] && tmp[i] <= 'Z')
            tmp[i] -= 'A'-'a';
    }
    cout << tmp << endl;
    return 0;
}
