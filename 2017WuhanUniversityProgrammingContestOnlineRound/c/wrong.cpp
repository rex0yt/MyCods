#include <iostream>
#include <cstring>

using namespace std;

const int NN = 100000 + 10;

char str[NN];
int prezero = 0;
int deletecount = 0;
int len;
int pfront, prear;
int rem;
/*
void DeleteZero()
{
    int i = 0;
    while(str[i] == 0)
    {
        i ++;
        deletecount ++;
    }
    prezero = i;
    return ;
}
*/
int mod2()
{
    int x = prear;
    while(str[prear] >> 1 == 1)
    {
        prear -- ;
    }
    return x-prear;
}
int main()
{
    cin >> str;
    rem = len = strlen(str);
    pfront = 0;
    prear = len - 1;
    while(rem > 0)
    {
        rem -= mod2();

    }

    return 0;
}
