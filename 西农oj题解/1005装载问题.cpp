#include <iostream>
using namespace std;

//int a[5] = {1,2,3,4,5};
int arr[10];
int sumall;

int ccnt(int layernow, int layerall, int cnt, int rongliang)
{
    if(layernow >= layerall)return cnt;
    if(cnt == rongliang)
        return rongliang;
    if(cnt+arr[layernow] > rongliang)
        return ccnt(layernow+1, layerall, cnt, rongliang);
    return max(ccnt(layernow+1, layerall, cnt+arr[layernow], rongliang),
               ccnt(layernow+1, layerall, cnt, rongliang));
}

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c&&(a||b||c))
    {
        sumall = 0;
        //input all data
        for(int i=0; i<c; i++)
        {
            cin >> arr[i];
            sumall += arr[i];
        }
        //calculate maximum weight can be loaded in a
        int pmax = ccnt(0,c,0,a);
        if(sumall - pmax <= b)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
