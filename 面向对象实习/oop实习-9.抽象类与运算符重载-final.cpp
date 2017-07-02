#include <bits/stdc++.h>
using namespace std;

const double PI=3.1415926;

class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    virtual double Area()=0;
    virtual void Show()=0;

    friend bool operator==(Shape &shLeft,Shape &shRight);
    friend bool operator<(Shape &shLeft,Shape &shRight);
    friend bool operator>(Shape &shLeft,Shape &shRight);
};

bool operator==(Shape &shLeft,Shape &shRight)
{
    return fabs(shLeft.Area()-shRight.Area())<=1.0e-8;
}

bool operator<(Shape &shLeft,Shape &shRight)
{
    return shLeft.Area()<shRight.Area();
}

bool operator>(Shape &shLeft,Shape &shRight)
{
    return shLeft.Area()>shRight.Area();
}

class Rectangle:public Shape
{
public:
    Rectangle(double w,double h);
    double Area();
    void Show();
private:
    double rectWidth;
    double rectHeight;
};

Rectangle::Rectangle(double w,double h):rectWidth(w),rectHeight(h)
{

}

double Rectangle::Area()
{
    return rectWidth*rectHeight;
}

void Rectangle::Show()
{
    cout<<"W: "<<rectWidth<<"; H:"<<rectHeight<<"; Area: "<<Area()<<endl;
}

class Eclipse:public Shape
{
public:
    Eclipse(double w,double h);
    double Area();
    void Show();
private:
    double rectWidth;
    double rectHeight;
};

Eclipse::Eclipse(double w,double h):rectWidth(w),rectHeight(h)
{

}

double Eclipse::Area()
{
    return rectHeight*rectWidth*PI/4;
}

void Eclipse::Show()
{
    cout<<"W: "<<rectWidth<<"; H:"<<rectHeight<<"; Area: "<<Area()<<endl;
}

int main()
{
    int shNum;
    cin>>shNum;
    Shape**shArr=new Shape*[shNum];
    char shType;
    double w,h;
    for(int i=0;i<shNum;i++)
    {
        cin>>shType>>w>>h;
        switch(shType)
        {
        case 'R':
            {
                shArr[i]=new Rectangle(w,h);
                break;
            }
        case 'E':
            {
                shArr[i]=new Eclipse(w,h);
                break;
            }
        }
    }
    for(int i=0;i<shNum;i++)
    {
        shArr[i]->Show();
    }
    for(int i=0;i<shNum;i++)
    {
        for(int j=i+1;j<shNum;j++)
        {
            if(*shArr[i]==*shArr[j])
            {
                cout<<"Area of Shape["<<i<<"] is equal to Shape["<<j<<"]"<<endl;
            }
        }
    }
    int k;
    Shape* shTemp;
    for(int i=0;i<shNum-1;i++)
    {
        k=i;
        for(int j=i+1;j<shNum;j++)
        {
            if(*shArr[j]>*shArr[k])
            {
                k=j;
            }
        }
        shTemp=shArr[i];
        shArr[i]=shArr[k];
        shArr[k]=shTemp;
    }
    for(int i=0;i<shNum;i++)
    {
        shArr[i]->Show();
    }
    return 0;
}
