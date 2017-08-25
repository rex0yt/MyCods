#include <iostream>
#define N 20+10

using namespace std;

int arr[N];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int maxv = -999999;
    int maxp = -1;
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        for(int j=0; j<4; j++)
        {
            cnt += arr[(i+j)%n];
        }
        if(cnt > maxv)
        {
            maxp = i;
            maxv = cnt;
        }
    }
    cout<<maxv<<endl<<maxp+1<<endl;
    return 0;
}
