#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

void to(char str[110][12],char *s,int *len){
    int pstr = 0,ps = 0;
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]==' '||s[i]=='\0'){
            str[pstr][ps]='\0';
            pstr++;ps=0;
        }else{
            str[pstr][ps++]=s[i];
        }
    }
    *len = ++pstr;
    return ;
}

int main()
{
    char s1[N],s2[N];
    char str1[110][12],str2[110][12];
    int len1,len2;

    gets(s1);
    gets(s2);

    to(str1,s1,&len1);
    to(str2,s2,&len2);
    if(len1!=len2){
        cout << "No\n";
        return 0;
    }else{
        for(int i=0;i<len1-1;i++)
            for(int j=i+1;j<len1;j++)
        {
            if(strcmp(str1[i],str1[j])==0)
                if(strcmp(str2[i],str2[j])!=0)
            {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}
