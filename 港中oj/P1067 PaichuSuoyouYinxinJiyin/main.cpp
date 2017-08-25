#include <iostream>

using namespace std;

int main()
{
    int a[1000];
    int n;

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++)
    {
        if(a[i]*a[i]%7 != 1)
        {
            cout<<a[i]<< ' ';
        }
    }
    cout<<endl;
    return 0;
}
