#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

char str0[1100],str1[1100];
int len0,len1;
int l[1100][1100];

int main(){

    int i,j;

    while(gets(str0)){
        gets(str1);
        len0 = strlen(str0);
        len1 = strlen(str1);

        /*for(i=0;i <= len0; i++)
            l[i][0] = 0;
        for(j= 0; j <= len1; j++)
            l[0][j] = 0;*/
        memset(l,0,sizeof(l));
        for(i = 1; i <= len0; i ++)
            for(j = 1; j <= len1; j++){
                if(str0[i-1] == str1[j-1])
                    l[i][j] = l[i-1][j-1] + 1;
                else if(l[i-1][j] >= l[i][j-1])
                    l[i][j] = l[i-1][j];
                else l[i][j] = l[i][j-1];
        }
        cout << l[len0][len1] << endl;

    }
    return 0;
}
