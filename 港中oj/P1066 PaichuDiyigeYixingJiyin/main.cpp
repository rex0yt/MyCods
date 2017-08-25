#include <iostream>

using namespace std;

int main()
{
    int a[1000];
    int n;

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    bool f = true;

    for(int i=0; i<n; i++)
    {
        if(f)
        {
            if(a[i]*a[i]%7 == 1)
            {
                f = false;
                continue;
            }
        }
        cout<<a[i]<< ' ';
    }
    cout<<endl;
    return 0;
}
