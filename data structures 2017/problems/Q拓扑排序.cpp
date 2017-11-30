using namespace std;
#include <iostream>
#include <cstring>

#define MaxN 1000

int n;
int cnt[MaxN];
int arr[MaxN][MaxN];
bool Used[MaxN];


bool IsCircled()
{
    int cntUsed = 0;
    for(int i=0; i<n; i++)
    {
        if(cnt[i])
            cntUsed++;
    }
    bool flag;
    while(1)
    {
        flag = false;
        for(int i=0; i<n; i++)
        {
            if(cnt[i] == 0 && Used[i] == false)
            {
                flag = true;
                Used[i] = true;
                for(int j=0; j<n; j++)
                {
                    if(arr[i][j])
                    {
                        cnt[j]--;
                        if(cnt[j] == 0)
                            cntUsed --;
                    }
                }
            }
        }
        if(flag == false)
        {
            if(cntUsed == 0)
                return false;
            return true;
        }
    }
}

int main()
{
    cin >> n;
    memset(cnt, 0x0, sizeof(cnt));
    memset(Used, 0x0, sizeof(Used));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j])
                cnt[j] ++;
        }
    }

    if(IsCircled())
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}