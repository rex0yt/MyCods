#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 2000+10

int main()
{
    int n, m, i, s=0;

    scanf("%d%d", &n, &m);

    for (i=2; i<=n; i++) s=(s+m)%i;

    printf ("%d\n", s+1);

    return 0;
}
