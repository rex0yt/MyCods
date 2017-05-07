#include <iostream>

using namespace std;

const int N = 41;

int a[40] = {0, 1, 2, 3};

int sol(int x){
    if(a[x] !=0)return a[x];
    a[x] = sol(x - 1) + sol(x - 2);
    return a[x];
}

int main()
{
    int x;
    cin >> x;
    cout << sol(x - 1) << endl;

    return 0;
}
