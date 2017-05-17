#include <bits/stdc++.h>
using namespace std;

class Cylinder
{
    double height, radius;
public:
    static const double pi = 3.1415926;
    double GetPi();
    Cylinder(double height=0, double radius=0):height(height),radius(radius){}
    double GetRadius();
    double GetHeight();
    void SetRadius(double radius);
    void SetHeight(double height);
    double Volume();
    double Area();
};

int main()
{
    double radius, height;
    cin >> height >> radius;
    Cylinder cylinder(height, radius);
    cout << "pi=" << cylinder.GetPi() << ", height=" << cylinder.GetHeight() <<
        ", radius=" << cylinder.GetRadius() << ":volume=" <<
        cylinder.Volume() << ", area=" << cylinder.Area();
    return 0;
}

double Cylinder::GetPi()
{
    return pi;
}
double Cylinder::GetRadius()
{
    return radius;
}
double Cylinder::GetHeight()
{
    return height;
}
void Cylinder::SetRadius(double radius)
{
    this->radius = radius;
}
void Cylinder::SetHeight(double height)
{
    this->height = height;
}
double Cylinder::Volume()
{
    return pi*radius*radius*height;
}
double Cylinder::Area()
{
    return 2*pi*radius*height + 2*pi*radius*radius;
}
