#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int abc(char *s){
    int sum = 0;
    for(int i=0;i<strlen(s);i++){
        sum+=s[i]-'0';
    }
    return sum;
}

int main(){
    char s[N];

    cin >> s;
    while(!(strlen(s)==1&&s[0]=='0')){
        while(abc(s)>=10){
            sprintf(s,"%d",abc(s));
        }
        cout << abc(s) << endl;
        cin >> s;
    }
    return 0;
}
