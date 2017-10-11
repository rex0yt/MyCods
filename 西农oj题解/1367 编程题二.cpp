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

void swap(int &a,int &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}
int main()
{
    initProgram();

    int arr[10];
    for(int i=0; i<10; i++)
    {
        cin >> arr[i];
    }

//    for(int i=0; i<10; i++)
//        cout<<arr[i]<<" ";


    int imax=0;
    for(int i=0; i<10; i++)
        if(arr[imax] < arr[i])
            imax = i;
    if(imax - 0)
        swap(arr[imax],arr[0]);

//    for(int i=0; i<10; i++)
//        cout<<arr[i]<<" ";

    int imin = 0;
    for(int i=0; i<10; i++)
        if(arr[i] < arr[imin])
            imin = i;
    if(imin - 9)
        swap(arr[imin],arr[9]);

    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";

    return 0;
}
