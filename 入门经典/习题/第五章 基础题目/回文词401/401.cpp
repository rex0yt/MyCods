#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

char s[30];
char str0[] = "AEHIJLMOSTUVWXYZ12358";
char str1[] = "A3HILJMO2TUVWXY51SEZ8";

bool is_pal(){
    int i = 0, j = strlen(s) - 1;
    for(;i < j;i ++, j --)
        if(s[i] != s[j])return false;
    return true;
}

bool is_mir(){
    int p0,p1;
    int i=0, j = strlen(s) - 1;
    for(;i<=j;i++,j--){
        p0=0;while(s[i] != str0[p0])p0 ++;
            if(p0>=strlen(str0))return false;
        p1=0;while(s[j] != str1[p1])p1 ++;
            if(p1>=strlen(str1))return false;
        if(p0 != p1)return false;
    }
    return true;
}

int main(){

    while(cin >> s){

        if(is_pal()){
            if(is_mir())
                cout << s << " -- is a mirrored palindrome." << endl;
            else
                cout << s << " -- is a regular palindrome." << endl;
        }
        else {
            if(is_mir())
                cout << s << " -- is a mirrored string." << endl;
            else
                cout << s << " -- is not a palindrome." << endl;
        }
        cout << endl;
    }
    return 0;
}
