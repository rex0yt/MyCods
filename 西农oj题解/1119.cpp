#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

struct a{
    char no[20];
    char sa[20];
    char sex[20];
    char age[20];
};



int main()
{
    a s[N];
    int i;
    char m[20];
    int f=0;

    for(int i=0;i<5;i++){
        cin >> s[i].no >> s[i].sa >> s[i].sex >>s[i].age;
    }
    cin >> m;
    for(i=0;i<5;i++)
        if(strcmp(s[i].age,m)==0){
            f=1;
            strcpy(s[i].no,"000");
        }
    int n=5;
    if(!f){
        strcpy(s[n].no,"180");
        strcpy(s[n].sa,"aaa");
        strcpy(s[n].age,m);
        strcpy(s[n].sex,"male");
        n++;
    }

    for(int i=0;i<n;i++){
        if(strcmp(s[i].no,"000")!=0)cout << s[i].no << endl << s[i].sa << endl << s[i].sex <<endl << s[i].age <<endl;
    }
    return 0;
}
