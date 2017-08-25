#include <iostream>

using namespace std;

int arr[40];
bool isBolang(int i,int jz)
{
    int len = 0;
    while(i)
    {
        arr[len++] = i%jz;
        i /= jz;
    }
    /*
    for(int i=len-1; i>=0; i--)
        cout<<arr[i]<< ' ';
    cout<<endl;
    */
    if(len <= 2)return false;
    if(arr[len-1]==arr[len-2])return false;

    int tmp = arr[len-1];
    for(int i=len-1; i>=0; i-=2)
    {
        if(tmp != arr[i])
            return false;
    }
    tmp = arr[len-2];
    for(int i=len-2; i>=0; i-=2)
    {
        if(tmp != arr[i])
            return false;
    }
    return true;
}

int main()
{
    int jz0,jz1,leftnum,rightnum,chongshu;
    cin>>jz0>>jz1>>leftnum>>rightnum>>chongshu;
    for(int i=leftnum; i<=rightnum; i++)
    {
        int cnt = 0;
        for(int j=jz0; j<=jz1; j++)
        {
            if(isBolang(i,j))
            {
                //cout<<j<<endl;
                cnt ++;
            }
        }
        if(cnt == chongshu)cout<<i<<endl;
    }
    return 0;
}
