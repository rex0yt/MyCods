#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int C[1005][1005] = {0};

int len(int a){
    int i = 999;
    while(!C[a][i])i --;
    return i;
}
int main()
{
    memset(C,0,sizeof(C));
    C[1][0] = 1;/* length */
    C[1][1] = 1;

    for (int i = 2 ; i < 1001 ; ++ i) {
        for (int j = 1 ; j <= C[i-1][0] /**/; ++ j)
            C[i][j] += C[i-1][j]*(4*i-2);

        for (int j = 1 ; j <= (C[i-1][0] + 10/**/); ++ j) {
            C[i][j+1] += C[i][j]/10;
            C[i][j] %= 10;
        }

        for (int j = (C[i-1][0] + 10/**/) ; j >= 0 ; -- j) {
            C[i][j-1] += C[i][j]%(i+1)*10;
            C[i][j] /= (i+1);
        }
        C[i][0] = len(i);
    }

    int n;
    while (cin >> n) {
        int end = C[n][0];
        while (end >= 1) printf("%d",C[n][end --]);
        printf("\n");
    }
    return 0;
}
