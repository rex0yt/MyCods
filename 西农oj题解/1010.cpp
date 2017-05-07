#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 200


int main()
{
    int n;
    cin >> n;
    for(int i=6;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<i;j++)
        {
            if(i%j==0)sum+=j;
        }
        if(i==sum)cout << i << endl;
    }

    return 0;
}
