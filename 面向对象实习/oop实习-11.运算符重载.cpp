#include <iostream>

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
        if(iUp>0&&iDown<0){
            iUp*=-1;
            iDown*=-1;
        }
     }
     int Gcd(int l,int r){
         if(l==0)return r;
         else return Gcd(r%l,l);
     }
public:
    Rational(int iup,int idown):
        iUp(iup),iDown(idown){
            Reduce();
    }
    const Rational operator-()const{
        return Rational(-iUp,iDown);
    }
    Rational operator=(const Rational& val){
        this->iUp=val.iUp;
        this->iDown=val.iDown;
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
        return left.iUp*right.iDown<left.iDown*right.iUp;
    }
    friend bool operator>(const Rational& left,const Rational& right){
        return left.iUp*right.iDown>left.iDown*right.iUp;
    }
    friend bool operator<=(const Rational& left,const Rational& right){
        return left.iUp*right.iDown<=left.iDown*right.iUp;
    }
    friend bool operator>=(const Rational& left,const Rational& right){
        return left.iUp*right.iDown>=left.iDown*right.iUp;
    }
    friend ostream& operator<<(ostream& os,const Rational&val){
        if(val.iDown==1)os<<val.iUp;
        else os<<val.iUp<<"/"<<val.iDown;
        return os;
    }
    friend istream& operator>>(istream& is,Rational&val){
        return is>>val.iUp>>val.iDown;
    }
};
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    Rational a1(a,b),a2(c,d);
    cout<<"a+b: "<<a1+a2<<endl;
    cout<<"a-b: "<<a1-a2<<endl;
    cout<<"a*b: "<<a1*a2<<endl;
    cout<<"a/b: "<<a1/a2<<endl;
    cout<<"-a: "<<-a1<<endl;
    cout<<"++a: "<<++a1<<endl;
    cout<<"--a: "<<--a1<<endl;
    cout<<"a++: "<<a1++<<endl;
    cout<<"a--: "<<a1--<<endl;
    bool w,x,y,z;
    w=a1<a2;
    x=a1<=a2;
    y=a1>a2;
    z=a1>=a2;
    cout<<"a<b: ";w?cout<<"true":cout<<"false";cout<<endl;
    cout<<"a<=b: ";x?cout<<"true":cout<<"false";cout<<endl;
    cout<<"a>b: ";y?cout<<"true":cout<<"false";cout<<endl;
    cout<<"a>=b: ";z?cout<<"true":cout<<"false";cout<<endl;
    return 0;
}
