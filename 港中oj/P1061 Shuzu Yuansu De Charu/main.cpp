#include <iostream>
#define N 10+3
using namespace std;

int arr[N];

int main()
{
    int n,pval,pnt;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cin >> pnt >> pval;
    bool f = true;
    for(int i=0; i<n; i++)
    {
        if(f)
        {
            if(pnt-1 == i)
            {
                cout<<pval<<' ';
                f = false;
            }
        }
        cout<<arr[i]<<' ';

    }
    cout<<endl;
    return 0;
}
