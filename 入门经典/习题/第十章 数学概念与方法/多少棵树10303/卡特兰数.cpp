#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int C[1005][1005] = {0};

int main()
{
    C[1][0] = 1;
    for (int i = 2 ; i < 1001 ; ++ i) {

        for (int j = 0 ; j < 1000 ; ++ j)
            C[i][j] += C[i-1][j]*(4*i-2);
        for (int j = 0 ; j < 1000 ; ++ j) {
            C[i][j+1] += C[i][j]/10;
            C[i][j] %= 10;
        }
        for (int j = 999 ; j >= 0 ; -- j) {
            C[i][j-1] += C[i][j]%(i+1)*10;
            C[i][j] /= (i+1);
        }
    }

    int n;
    while (cin >> n) {
        int end = 999;
        while (!C[n][end]) -- end;
        while (end >= 0) printf("%d",C[n][end --]);
        printf("\n");
    }
    return 0;
}
