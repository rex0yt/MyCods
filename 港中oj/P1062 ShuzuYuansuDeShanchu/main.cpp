#include <iostream>
#define N 1000+3
using namespace std;

int arr[N];

int main()
{
    int n,pnt;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cin >> pnt;

    for(int i=0; i<n; i++)
    {
        if(pnt-1 != i)
            cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}
