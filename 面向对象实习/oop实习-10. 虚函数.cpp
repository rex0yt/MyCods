#include <bits/stdc++.h>

using namespace std;

class Person
{
protected:
    string szName;
public:
    virtual void Print(){
        cout<<"Person "<<szName<<endl;
    }
    Person(string name)
    :szName(name){}
};
class Student:public Person
{
protected:
    int iNumber;
public:
    Student(string name,int number):
        Person(name),iNumber(number){}
    void Print(){
        cout<<"Student "<<szName<<" "<<iNumber<<endl;
    }
};
class Teacher:public Person
{
protected:
    int iYear;
public:
    Teacher(string name,int year):
        Person(name),iYear(year){}
    void Print(){
        cout<<"Teacher "<<szName<<" "<<iYear<<endl;
    }
};
class Graduate:public Student
{
protected:
    string szResearch;
public:
    Graduate(string name,int num,string res):
        Student(name,num),szResearch(res){}
    void Print()
    {
        cout<<"Graduate "<<szName<<" "<<iNumber<<" "<<szResearch<<endl;
    }
};
int main()
{
    Person **arr;
    int n;
    string tmp,xx,xxxx;
    int xxx;

    cin >> n;
    arr = new Person* [n];
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        if(tmp=="Person"){
            cin>>xx;
            arr[i]=new Person(xx);
        }else if(tmp=="Student"){
            cin>>xx>>xxx;
            arr[i]=new Student(xx,xxx);
        }else if(tmp=="Graduate"){
            cin>>xx>>xxx>>xxxx;
            arr[i]=new Graduate(xx,xxx,xxxx);
        }else if(tmp=="Teacher"){
            cin>>xx>>xxx;
            arr[i]=new Teacher(xx,xxx);
        }
    }
    do{
        cin>>xx;
        if(xx=="exit")break;
        stringstream stream;
        stream<<xx;
        stream>>xxx;
        arr[xxx]->Print();
    }while(1);
    return 0;
}
