#include <iostream>
#include <cstring>


using namespace std;

/*
*【任务】：
    给定一个正整数N，将N分解质因数。
*【说明】：
    N的质因数要么是N本身（N是素数），要么一定小于等于根号N。因此可以用小于等于根号N
    的数对N进行试除，一直到不能除为止。这时候剩下的数如果不是1，那就是N最大的质因数。
*【接口】：
    void factor(int n,int a[maxn],int b[maxn],int &tot);
    复杂度：O(根号 N)
    输入：n    待分解的整数
    输出：&tot 不同质因数的个数
            a   a[i]表示第i个质因数的值
            b   b[i]表示第i个质因数的指数
*【代码】
*/
#include <cmath>
#define maxn 10000

void factor(int n,int a[maxn],int b[maxn],int &tot){
    int temp,i,now;
    temp = (int)((double)sqrt(n)+1);
    tot = 0;
    now = n;
    for(i = 2;i <= temp; ++ i)
    if(now % i == 0){
        a[++ tot] = i;
        b[tot] = 0;
        while(now % i == 0){
            ++b[tot];
            now /= i;
        }
    }
    if(now != 1){
        a[++tot] = now;
        b[tot] = 1;
    }
}

int main(){

    return 0;
}
