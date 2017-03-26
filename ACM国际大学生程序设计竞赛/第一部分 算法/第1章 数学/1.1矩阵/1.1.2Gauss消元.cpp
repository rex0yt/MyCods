/**
 *【任务】
 *      给一个n元一次方程组，求它们的解集
 *【说明】
 *      将方程组做成矩阵形式，再利用三种初等变换，得到上三角形，最后回代得到解集
 *【接口】
 *      int solve(double a[][MAXN],bool l[],double ans[],ocnst int &n);
 *      复杂度
 *          O(n^3)
 *      输入
 *          a       方程组对应的矩阵
 *          n       未知数个数
 *          l，ans   储存解，l[]表示是否为自由元
 *      输出
 *          解空间的维数
 */

#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 1000;
const int EPS = 1;

inline int solve(double a[][MAXN],bool l[],double ans[],const int &n){
    int res = 0, r = 0;
    for(int i=0;i<n;i++)l[i]=false;
    for(int i=0;i<n;i++){
        for(int j=r;j<n;j++)
            if(fabs(a[j][i]) < EPS){
                for(int k=i;k<n;++k)
                    swap(a[j][k],a[r][k]);
                break;
            }
        if(fabs(a[r][i]<EPS)){
            ++res;
            continue;
        }
        for(int j=0;j<n;j++)
            if(j!=r && fabs(a[i][j])>EPS){
                double tmp = a[j][i] / a[r][i];
                for(int k=i;k<n;k++)
                    a[j][k]-=tmp*a[r][k];
            }
        l[i]=true,++r;
    }
    for(int i=0;i < n; i ++)
        if(l[i])
            for(int j=0;j < n; j ++)
                if(fabs(a[j][i]) > 0)
                    ans[i] = a[j][n] / a[j][i];
    return res;
}
int main(){

    return 0;
}
