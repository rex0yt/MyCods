#include <bits/stdc++.h>

using namespace std;

class Point
{
public:
    double x;
    double y;
    Point(double x,double y):x(x),y(y){}
};
class Line
{
public:
    Point p1;
    Point p2;
    Line(const Point&p1,const Point&p2):p1(p1),p2(p2){}
    double len()
    {
        return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    }
};
class Triangle
{
public:
    Point p1,p2,p3;
    Triangle(const Point&p1,const Point&p2,const Point&p3):p1(p1),p2(p2),p3(p3){}
    double circle()
    {
        Line l1(p1,p2),l2(p2,p3),l3(p1,p3);
        return l1.len()+l2.len()+l3.len();
    }
    double area()
    {
        Line l1(p1,p2),l2(p2,p3),l3(p1,p3);
        double a = l1.len();
        double b = l2.len();
        double c = l3.len();
        double p = 0.5*(a+b+c);
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
};
int main()
{
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Point p1(x1,y1),p2(x2,y2),p3(x3,y3);
    Triangle t(p1,p2,p3);
    cout<<t.circle()<<" "<<t.area()<<endl;

    return 0;
}
