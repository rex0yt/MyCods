/**
 *【任务】
 *      给一个矩阵，求它的逆矩阵
 *【说明】
 *      将原矩阵A和一个单位矩阵E作成大矩阵（A,E），用初等行变换将大矩阵中的A变为E，则会得到（E,A^-1）的形式
 *【接口】
 *      void inverse(vector<double> A[],vector <double> C[],int N);
 *      复杂度
 *          O(n^3)
 *      输入
 *          A   原矩阵
 *          C   逆矩阵
 *          N   矩阵的阶数
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

inline vector<double> operator *(vector<double> a,double b){
    int N = a.size();
    vector<double> res(N,0);
    for(int i = 0; i < N; i ++){
        res[i] = a[i] * b;
    }
    return res;
}
inline vector<double> operator -(vector<double> a,vector<double> b){
    int N=a.size();
    vector<double> res(N,0);
    for(int i = 0; i < N; i ++){
        res[i]=a[i] - b[i];
        return res;
    }
}
inline void inverse(vector<double> A[],vector<double> C[],int N){
    for(int i = 0; i < N; i ++)
        C[i] = vector<double> (N,0);
    for(int i = 0; i < N; i ++){
        C[i][i] = 1;
    }
    for(int i=0;i < N; i ++){
        for(int j= i; j < N; j ++){
            if(fabs(A[j][i]) > 0){
                swap(A[i], A[j]);
                swap(C[i], C[j]);
                break;
            }
        }
        C[i] = C[i] * (1 / A[i][i]);
        A[i] = A[i] * (1 / A[i][i]);
        for(int  j= 0; j < N; j ++){
            if(j != i && fabs(A[j][i]) > 0){
                C[j] = C[j] - C[i] * A[j][i];
                A[j] = A[j] - A[i] * A[j][i];
            }
        }
    }
}
int main(){

    return 0;
}
