#include <bits/stdc++.h>

using namespace std;

class StudentRecord
{
public:
    string stuName;
    int stuNo;
    void print()
    {
        cout<<"Name: "<<stuName<<", Number: "<<stuNo<<endl;
    }
};
class StudentNode
{
public:
    StudentRecord data;
    StudentNode* next;
    StudentNode(StudentRecord data,StudentNode* next=NULL):
        data(data),next(next){}
};
class LinkedList
{
public:
    StudentNode* head;
    LinkedList()
    {
        head = NULL;
    }
    void headinsert(StudentNode tmp)
    {
        if(head==NULL)
        {
            head = new StudentNode(tmp.data,NULL);
        }
        else
        {
            StudentNode* p;
            p = new StudentNode(tmp.data,head);
            head = p;
        }
    }
    void headdelete()
    {
        if(head->next==NULL)
        {
            head = NULL;
        }
        else
        {
            StudentNode* tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }
    void tailinsert(StudentNode tmp)
    {

        if(head == NULL)
        {
            head = new StudentNode(tmp.data,NULL);
        }
        else
        {
            StudentNode* p = head;
            while(p->next)
            {
                p = p->next;
            }
            p->next = new StudentNode(tmp.data,NULL);
        }
    }
};
class LinkedStack:public LinkedList
{
public:
    void Push(StudentRecord record)
    {
        StudentNode tmp(record,NULL);
        headinsert(tmp);
    }
    bool Pop(StudentRecord &record)
    {
        if(head == NULL)return false;
        else
        {
            StudentNode tmp = *head;
            record = tmp.data;
            headdelete();
        }
        return true;
    }
};
class LinkedQueue:public LinkedList
{
public:
    void EnQueue(StudentRecord record)
    {
        StudentNode tmp(record,NULL);
        tailinsert(tmp);
    }
    bool DeQueue(StudentRecord &record)
    {
        if(head == NULL)return false;
        else
        {
            StudentNode tmp = *head;
            record = tmp.data;
            headdelete();
        }
        return true;
    }
};
int main()
{
    LinkedQueue queue;
    LinkedStack stack;
    string type;
    do{
        cin >> type;
        if(type=="Push")
        {
            StudentRecord tmp;
            cin>>tmp.stuName>>tmp.stuNo;
            stack.Push(tmp);
        }
        else if(type=="EnQueue")
        {
            StudentRecord tmp;
            cin>>tmp.stuName>>tmp.stuNo;
            queue.EnQueue(tmp);
        }
        else if(type=="Pop")
        {
            StudentRecord tmp;
            if(!stack.Pop(tmp))cout<<"Stack is empty!"<<endl;
            else
            {
                tmp.print();
            }
        }
        else if(type=="DeQueue")
        {
            StudentRecord tmp;
            if(!queue.DeQueue(tmp))cout<<"Queue is empty!"<<endl;
            else
            {
                tmp.print();
            }
        }
        else if(type=="Exit")
        {
            break;
        }
        else
        {
            cout<<"Input error!"<<endl;
        }
    }while(1);
    return 0;
}
