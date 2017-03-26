#include <iostream>

using namespace std;

int f;
int c;

void input()
{
    cin >> f;
    return ;
}
void calc()
{
    c = 5 * (f - 32) / 9;
    return ;
}
void output()
{
    cout << "Celsius = " << c << endl;
}
int main()
{
    input();
    calc();
    output();
    return 0;
}
