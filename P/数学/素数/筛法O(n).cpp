#include <iostream>
#include <cstring>

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
    复杂度：O(N)
    输入：N    所需素数的范围
    输出：&tot 引用，素数总数
          ans  素数表
*【代码】
*/

#define maxn 1000000

bool valid[maxn];

void getPrime(int n,int &tot,int ans[maxn]){
    memset(valid,true,sizeof(valid));
    for(int i = 2; i <= n; i ++){
        if(valid[i]){
            ans[++ tot] = i;
        }
        for(int j = 1;((j <= tot) && (i * ans[j] <= n)); j ++){
            valid[i*ans[j]] = false;
            if(i%ans[j] == 0)break;
        }
    }
}

int main(){

    return 0;
}
