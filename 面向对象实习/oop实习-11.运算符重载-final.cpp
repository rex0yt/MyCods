#include <bits/stdc++.h>
using namespace std;

class Rational
{
private:
     int iUp;
     int iDown;
     void Reduce(){
        int tmp = Gcd(iUp,iDown);
        iUp /= tmp;
        iDown /= tmp;
        if(iUp>0 && iDown<0){
            iUp*=-1;
            iDown*=-1;
        }
     }
     int Gcd(int l,int r){
         return r==0?l:Gcd(r,l%r);
     }
public:
    Rational(int iup = 0,int idown = 1):
        iUp(iup),iDown(idown){
            Reduce();
    }
    const Rational operator-()const{
        return Rational(-iUp,iDown);
    }
    Rational operator=(const Rational& val){
        this->iUp = val.iUp;
        this->iDown = val.iDown;
        return *this;
    }
    const Rational& operator++(){
        iUp+=iDown;
        return *this;
    }
    const Rational operator++(int){
        Rational before(iUp,iDown);
        iUp+=iDown;
        return before;
    }
    const Rational& operator--(){
        iUp-=iDown;
        return *this;
    }
    const Rational operator--(int){
        Rational before(iUp,iDown);
        iUp -= iDown;
        return before;
    }
    friend const Rational operator+(const Rational& left,const Rational& right){
        return Rational(left.iUp*right.iDown+left.iDown*right.iUp,left.iDown*right.iDown);
    }
    friend const Rational operator-(const Rational& left,const Rational& right){
        return Rational(left.iUp*right.iDown-left.iDown*right.iUp,left.iDown*right.iDown);
    }
    friend const Rational operator*(const Rational& left,const Rational& right){
        return Rational(left.iUp*right.iUp,left.iDown*right.iDown);
    }
    friend const Rational operator/(const Rational& left,const Rational& right){
        return Rational(left.iUp*right.iDown,left.iDown*right.iUp);
    }
    friend bool operator<(const Rational& left,const Rational& right){
        Rational tmp = left - right;
        return tmp.iUp<0;
    }
    friend bool operator>(const Rational& left,const Rational& right){
        Rational tmp = left - right;
        return tmp.iUp>0;
    }
    friend bool operator<=(const Rational& left,const Rational& right){
        Rational tmp = left - right;
        return tmp.iUp<=0;
    }
    friend bool operator>=(const Rational& left,const Rational& right){
        Rational tmp = left - right;
        return tmp.iUp>=0;
    }
    friend ostream& operator<<(ostream& os,const Rational&val){
        if(val.iDown==1)os<<val.iUp;
        else os<<val.iUp<<"/"<<val.iDown;
        return os;
    }
    friend istream& operator>>(istream& is,Rational &val){
        int up,down;
        is >> up >> down;
        val = Rational(up,down);
        return is;
    }
};
int main()
{
    Rational a1,a2;
    cin >> a1 >> a2;

    cout<<"a+b: "<<a1+a2<<endl;
    cout<<"a-b: "<<a1-a2<<endl;
    cout<<"a*b: "<<a1*a2<<endl;
    cout<<"a/b: "<<a1/a2<<endl;
    cout<<"-a: "<<-a1<<endl;
    cout<<"++a: "<<++a1<<endl;
    cout<<"--a: "<<--a1<<endl;
    cout<<"a++: "<<a1++<<endl;
    cout<<"a--: "<<a1--<<endl;

    cout<<"a<b: "<<boolalpha<<(a1<a2)<<endl;
    cout<<"a<=b: "<<boolalpha<<(a1<=a2)<<endl;
    cout<<"a>b: "<<boolalpha<<(a1>a2)<<endl;
    cout<<"a>=b: "<<boolalpha<<(a1>=a2)<<endl;
    return 0;
}
