#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 110;

char str1[N],str2[N];
char s2[N],s3[N],s4[N],s5[N];
int p1  //<
    ,p2 //>
    ,p3 //<
    ,p4 //>
    ,p5;//...

int main(){
    int num_case;
    int i,j;

    cin >> num_case;getchar();
    while(num_case --){

        cin.getline(str1,1000);
        cin.getline(str2,1000);
        i=0;
        while(str1[i] != '<')i ++;p1 = i;
        while(str1[i] != '>')i ++;p2 = i;
        while(str1[i] != '<')i ++;p3 = i;
        while(str1[i] != '>')i ++;p4 = i;
        i=0;
        while(str2[i] != '.')i ++;p5 = i;
        str2[p5]='\0';

        for(i=p1+1,j=0;i<p2;i++,j++)s2[j]=str1[i];
        s2[j]='\0';
        for(i=p2+1,j=0;i<p3;i++,j++)s3[j]=str1[i];
        s3[j]='\0';
        for(i=p3+1,j=0;i<p4;i++,j++)s4[j]=str1[i];
        s4[j]='\0';
        for(i=p4+1,j=0;i<strlen(str1);i++,j++)s5[j]=str1[i];
        s5[j]='\0';
        str1[p1]='\0';

        cout << str1 << s2 << s3 << s4 << s5 << endl;
        cout << str2 << s4 << s3 << s2 << s5 << endl;
    }

    return 0;
}
