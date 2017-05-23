#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string Gender;
    int Age;
public:
    string Name;

    Person(string name,string gender,int age)
        :Gender(gender),Age(age),Name(name)
    {
        cout<<"Person"<<Name<<"constructed"<<endl;
    }
    ~Person()
    {
        cout<<"Person"<<Name<<"destructed"<<endl;
    }
    void setName(string name)
    {
        Name = name;
    }
};
class StudentRecord:virtual public Person
{
protected:
    int Score;
public:
    string Number;
    string ClassName;
    static int TotalCount;

    StudentRecord(string name,string gender,int age,
                  string number,string classname,int totalcount,int score)
        :Person(name,gender,age),
         Score(score),Number(number),ClassName(classname)
    {
        TotalCount = totalcount;
        cout<<"Student"<<Name<<"constructed"<<endl;
    }
    ~StudentRecord()
    {
        cout<<"Student"<<Name<<"destructed"<<endl;
    }
};
class TeacherRecord:virtual public Person
{
protected:
    int Year;
public:
    string CollegeName;
    string DepartmentName;

    TeacherRecord(string name,string gender,int age,
                  string collegename,string departmentname,int year)
        :Person(name,gender,age),
         Year(year),CollegeName(collegename),DepartmentName(departmentname)
    {
        cout<<"teacher"<<Name<<"constructed"<<endl;
    }
    ~TeacherRecord()
    {
        cout<<"teacher"<<Name<<"destructed"<<endl;
    }
};
class TeachingAssistant:public StudentRecord,public TeacherRecord
{
public:
    string LectureName;

    string getLectureName()const
    {
        return LectureName;
    }
    void show()
    {
        cout<<"Name:"<<Name;
        cout<<" Gender:"<<Gender;
        cout<<" Age:"<<Age;
        cout<<" Number:"<<Number;
        cout<<" ClassName:"<<ClassName;
        cout<<" TotalCount:"<<TotalCount;
        cout<<" Score:"<<Score;
        cout<<" CollegeName:"<<CollegeName;
        cout<<" DepartmentName:"<<DepartmentName;
        cout<<" Year:"<<Year;
        cout<<" LectureName:";
        cout<<LectureName;
        cout<<endl;
    }
    TeachingAssistant(string name,string gender,int age,
                      string number,string classname,int totalcount,int score,
                      string collegename,string departmentname,int year,string lecturename)
        :Person(name,gender,age),
         StudentRecord(name,gender,age,number,classname,totalcount,score),
         TeacherRecord(name,gender,age,collegename,departmentname,year),LectureName(lecturename)
    {
        cout<<"teachingassistant"<<Name<<"constructed"<<endl;
    }
    ~TeachingAssistant()
    {
        cout<<"teachingassistant"<<Name<<"destructed"<<endl;
    }
};

int StudentRecord::TotalCount = 0;

int main()
{
    TeachingAssistant ta((string)"郑七","男",22,"2010123","软20101",1,89,"信息","软件",1,"数据结构");
    ta.show();
    ta.setName("郑八");
    ta.show();
    return 0;
}
