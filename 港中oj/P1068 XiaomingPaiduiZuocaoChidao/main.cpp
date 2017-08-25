#include <iostream>

using namespace std;

int main()
{
    int n;
    int a[1000];
    int pntx,pntm;

    cin>>n>>pntx>>pntm;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    if(a[n-1] == pntx)
    {
        for(int i=0; i<n; i++)
            cout<<a[i]<< ' ';
        cout<<pntm<<endl;
    }
    else
    {
        for(int i=0; i<n-1; i++)
        {
            if(a[i] == pntx)
            {
                cout<<a[i]<< ' ';
                cout<<pntm<< ' ';
            }
            else
                cout<<a[i]<< ' ';
        }
        cout<<a[n-1]<<endl;
    }

    return 0;
}
