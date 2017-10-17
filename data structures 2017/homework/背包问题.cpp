using namespace std;

#include <bits/stdc++.h>
#define MaxN 1000

int n;  //物品总数n
int weight[MaxN];//每个物品的重量
int WeightBag; //背包的总容量


bool KNAP(int s, int n)//递归函数
{
    if (s == 0) return true;
    if (s < 0) return false;
    if (s>0 && n<1) return false;
    return KNAP(s, n-1) ||
        KNAP(s-weight[n], n-1);
}

int main()
{
    cin >> n >> WeightBag;//输入
    for(int i=1; i<=n; i++)
        cin >> weight[i];

    cout << boolalpha << KNAP(WeightBag, n);//求解，输出
    return 0;
}
