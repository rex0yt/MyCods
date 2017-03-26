#include <iostream>

using namespace std;

/*【任务】：
    求两个数a，b的最大公约数gcd(a,b),且求出x，y满足ax+by=gcd(a,b)。
*【说明】：
    要求x，y满足ax+by=gcd(a,b)。
    当b=0时，有x=1，y=0使得等式成立。
    当b>0时，在欧几里得算法的基础上，已知：
                gcd(a,b) = gcd(a,a mod b)
    先递归求出x1，y1满足：
                b*x1+(a mod b)*y1 = gcd(b,a mod b) = gcd(a,b)
    然后可以回推，我们将上式化简得：
                b*x1 + (a-a/b*b)*y1 = gcd(a,b)
                a*y1 + b*x1 - (a/b)*b*y1 = gcd(a,b)
    这里除法指整除。把含b的因式提取一个b，可得：
                a*y1 + b*(x1-a/b*y1) = gcd(a,b)
    故x = y1, y = x1-a/b*y1。
*【接口】
    int extend_gcd(int a,int b,int &x,int &y);
    复杂度：O(logN),其中N与a，b同阶。
    输入：a，b      两个整数
            &x,&y   引用，ax+by=gcd(a,b)的一组解
    输出：a，b的最大公约数
    调用后x，y满足方程ax+by=gcd(a,b)。
*/

int extend_gcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1;y = 0;
        return a;
    }else{
        int r = extend_gcd(b,a%b,y,x);
        y -= x*(a/b);
        return r;
    }
}

int main(){
    return 0;
}
