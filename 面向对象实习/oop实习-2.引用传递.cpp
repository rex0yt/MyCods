#include <bits/stdc++.h>
using namespace std;

void Math(float a,float b,float &sum,float &sub,float &pro);

int main()
{
    float a, b, sum, sub, pro;
    cin >> a >> b;
    Math(a, b, sum, sub, pro);
    cout << sum << " " << sub << " " << pro;
    return 0;
}

void Math(float a,float b,float &sum,float &sub,float &pro)
{
    sum = a + b;
    sub = a - b;
    pro = a * b;
    return ;
}
