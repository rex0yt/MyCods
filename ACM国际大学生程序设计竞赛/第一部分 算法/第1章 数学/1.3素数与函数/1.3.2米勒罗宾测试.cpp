#include <iostream>
#include <cstring>

using namespace std;

/*
*【任务】：
    给定一个正整数N，判断N是否为素数。
*【说明】：
    Miller-Rabin测试：要测试N是否为素数，首先将N-1分解为(2^s)*d。在每次测试开始时，
    先随机选一个介于[1,N-1]的整数a，如果对所有的r属于[0,s-1]都满足a^d mod N != 1且
    a^((2^r)*d) mod N != -1，则是合数。否则，N有3/4的几率为素数。为了提高测试的正确
    性，可以选择不同的a进行多次测试。
*【接口】：
    bool isPrime(int N);
    复杂度：O(log N)
    输入：N    待测试的整数
    输出：FALSE表示N为合数，TRUE表示N有很大几率为素数。
*【调用外部函数】：
    快速幂
*【代码】
*/

bool test(int n,int a,int d){
    if(n == 2)return true;
    if(n == a)return true;
    if((n&1) == 0)return false;
    while(!(d&1))d=d >> 1;
    int t = pow_mod(a,d,n);
    while((d != n-1) && (t != 1) && (t != n-1)){
        t = (long long)t * t % n;
        d = d << 1;
    }
    return (t == n-1 || (d&1) == 1);
}

bool isPrime(int n){
    if(n < 2)return false;
    int a[] = {2,3,61}; //测试集，更广的测试范围需要更大的测试集
    for(int i = 0;i <= 2; ++ i)
        if(!test(n,a[i],n-1))return false;
    return true;
}

int main(){

    return 0;
}
