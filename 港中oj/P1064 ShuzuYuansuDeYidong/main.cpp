#include <iostream>
#define N 10000+3
using namespace std;

int arr[N];

int main()
{
    int n,pnt;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cin >> pnt;

    for(int i=0; i<pnt-1; i++)
    {
        cout<<arr[i]<< ' ';
    }
    for(int i=pnt; i<n; i++)
    {
        cout<<arr[i]<< ' ';
    }
    cout<<arr[pnt-1]<<endl;
    return 0;
}
