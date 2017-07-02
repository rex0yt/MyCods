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
    string type,name,research;
    int num;

    cin >> n;
    arr = new Person* [n];
    for(int i=0; i<n; i++)
    {
        cin >> type;
        if(type=="Person"){
            cin>>name;
            arr[i]=new Person(name);
        }else if(type=="Student"){
            cin>>name>>num;
            arr[i]=new Student(name,num);
        }else if(type=="Graduate"){
            cin>>name>>num>>research;
            arr[i]=new Graduate(name,num,research);
        }else if(type=="Teacher"){
            cin>>name>>num;
            arr[i]=new Teacher(name,num);
        }
    }
    string tmp;
    do{
        cin>>tmp;
        if(tmp[0]=='e')break;
        int index = tmp[0]-'0';
        arr[index]->Print();
    }while(1);
    return 0;
}
