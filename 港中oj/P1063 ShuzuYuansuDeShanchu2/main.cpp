#include <iostream>
#define N 10000+3
using namespace std;

int arr[N];

int main()
{
    int n,pval;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cin >> pval;
    int pnt = -1;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == pval)
        {
            pnt = i;
            break;
        }
    }

    if(pnt == -1)cout<<"no"<<endl;
    else
    {
        for(int i=0; i<n; i++)
        {
            if(i != pnt)
                cout<<arr[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
