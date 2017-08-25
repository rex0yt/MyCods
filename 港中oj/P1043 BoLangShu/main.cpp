#include <stdio.h>
#include <string.h>

using namespace std;

const int MaxN = 21000000 + 100;

short imap[MaxN];
int arr[40];
int leftnum, rightnum, jz0, jz1, chongshu;

int ilen(int num, int jz)
{
    if(num == 0)return 1;
    int ans = 0;
    while(num)
    {
        num /= jz;
        ans ++;
    }
    return ans;
}
int change(int len, int jz)
{
    int ans = 0;
    for(int i=0; i<=len; i++)
    {
        ans *= jz;
        ans += arr[i];
    }
    return ans;
}
void getans(int jz)
{
    int ans = 0;
    for(int i=1; i<jz; i++)
    for(int j=0; j<jz; j++)
        if(i != j)
        {
            int beg = ilen(1, jz);
            int fnl = ilen(10000000, jz);
            for(int len=0; ; len++)
            {
                len%2 ? arr[len]=j : arr[len]=i;
                if(beg <= len+1 && len+1 <= fnl)
                //if(len >= 2)
                {
                    ans = change(len, jz);
                    if(ans > 10000000)break;
                    imap[ans] ++;
                }
                if(len+1 > fnl)break;
            }
        }
}
void init()
{
    scanf("%d %d %d %d %d",&jz0, &jz1, &leftnum, &rightnum, &chongshu);
    for(int i=jz0; i<=jz1; i++)
        getans(i);
}
int main()
{
    init();
    for(int i=leftnum; i<=rightnum; i++)
        if(imap[i] == chongshu)
            printf("%d\n",i);
    return 0;
}
