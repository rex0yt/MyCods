#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 1000+20

int main()
{

    int a,b;
    char ch;

    scanf("%d%c%d",&a,&ch,&b);
    switch(ch)
    {
        case '+':cout << a+b << endl;break;
        case '-':cout << a-b << endl;break;
        case '*':cout << a*b << endl;break;
        case '/':cout << a/b << endl;break;
    }
    return 0;
}
