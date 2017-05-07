#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char s[7][20]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
    int n;
    cin >> n;
    cout << s[n-1] << endl;

    return 0;
}
