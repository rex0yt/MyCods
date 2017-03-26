#include <iostream>

using namespace std;

/*
*【任务】：
    给定一个正整数N，求出[2,N]中的所有素数。
*【说明】：
    数组valid[i]记录i是否为素数。初始所有的valid[i]都为true。从2开始从大到小
枚举i，若valid[i]=true,则把从i^2开始的每一个i的倍数的valid赋值为false。
    结束之后valid[i]=true的就是素数。
*【接口】：
    void getPrime(int n,int &tot,int ans[maxn])
    复杂度：O(NlogN)
    输入：N    所需素数的范围
    输出：&tot 引用，素数总数
          ans  素数表
*【代码】
*/

#define maxn 1000000

bool valid[maxn];

void getPrime(int n,int &tot,int ans[maxn]){
    tot = 0;
    int i, j;
    for(i = 2; i <= n; ++ i)valid[i] = true;
    for(i = 2; i <= n; ++ i)
        if(valid[i]){
            if(n/i < i)break;
            for(j = i*i; j <= n; j += i)
                valid[j] = false;
        }
    for(i = 2;i <= n; ++ i)
        if(valid[i])ans[++tot] = i;
}

int main(){

    return 0;
}
