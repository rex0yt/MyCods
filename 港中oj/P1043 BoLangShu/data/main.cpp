#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));
    cout<<2<<' '<<32<<' ';
    int rgt = rand();
    int lef = rand()*100;
    int chongshu = rand()%3 + 2;
    cout<<rgt<<' '<<lef<<' '<<chongshu<<endl;
    return 0;
}
