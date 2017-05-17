#include <bits/stdc++.h>
using namespace std;

double dis(double p1x, double p1y, double p1z, double p2x=0, double p2y=0, double p2z=0);

int main()
{
    double a, b, c;
    double x, y, z;

    cin >> a >> b >> c >> x >> y >> z;
    cout << dis(a, b, c) << endl << dis(a, b, c, x, y, z);

    return 0;
}

double dis(double p1x, double p1y, double p1z, double p2x, double p2y, double p2z)
{
    return sqrt((p1x-p2x)*(p1x-p2x)
            +(p1y-p2y)*(p1y-p2y)+(p1z-p2z)*(p1z-p2z));
}
