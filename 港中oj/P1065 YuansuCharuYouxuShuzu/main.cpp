#include <iostream>
#define N 1000
using namespace std;

int arr[N];

int main()
{
    int val;
    int n;

    cin >> val;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int i;
    for(i=0; i<n; i++)
        if(arr[i] >= val)
            break;

    for(int j=0; j<i; j++)
        cout<<arr[j]<< ' ';
    cout<<val<< ' ';
    for(int j=i; j<n; j++)
        cout<<arr[j]<< ' ';
    cout<<endl;

    return 0;
}
