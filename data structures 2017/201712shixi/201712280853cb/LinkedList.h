#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED

#include <iostream>
using namespace std;

template<typename Type>
struct DoubleLinkNode//双向链表节点
{
    Type data;
    DoubleLinkNode<Type>* lLink;
    DoubleLinkNode<Type>* rLink;
//      没有元素信息的默认构造函数
    DoubleLinkNode(DoubleLinkNode<Type>* pre=NULL,DoubleLinkNode<Type>*suc=NULL)
    {
        lLink=pre;
        rLink=suc;
    }
//      带有元素信息的构造函数
    DoubleLinkNode(const Type& elem, DoubleLinkNode<Type>* pre=NULL,DoubleLinkNode<Type>* suc=NULL)
    {
        data=elem;
        lLink=pre;
        rLink=suc;
    }
//    重载输出函数
    friend ostream& operator<<(ostream& os,DoubleLinkNode<Type>& node)
    {
        os << node.data;
        return os;
    }
};


template<typename Type>
class DoubleLinkedList//双向链表类
{
private:
    DoubleLinkNode<Type> head;//指向链表的头指针
    int length;
public:
    DoubleLinkedList():length(0)//默认构造函数 初始化链表
    {
        head.lLink = NULL;
        head.rLink = NULL;
    }
//    通过Type类型的数组初始化构造双向链表
    DoubleLinkedList(vector<Type>& typeArray)
    {
        int len = typeArray.size();
        this->length = len;
        DoubleLinkNode<Type> *pnt;
        DoubleLinkNode<Type> *tmp = &head;

        for(int i=0; i<len; i++)
        {
            pnt = new DoubleLinkNode<Type>();
            pnt->data = typeArray[i];
            pnt->lLink = tmp;
            pnt->rLink = NULL;
            tmp->rLink = pnt;
            tmp = tmp->rLink;
        }
    }
    void MakeEmpty()//使链表为空
    {
        DoubleLinkNode<Type>* del = head.rLink;
        DoubleLinkNode<Type>* tmp = del->rLink;
        while(tmp != NULL)
        {
            delete del;
            del = tmp;
            tmp = tmp->rLink;
        }
    }
    ~DoubleLinkedList()//析构函数
    {
        MakeEmpty();
        head.lLink=head.rLink=NULL;
    }
//    所有数据输出到vector中，等待保存
    bool Output(vector<Type>& personArray)
    {
        personArray.clear();
        DoubleLinkNode<Type> *pnt = head;
        Type tmp;
        for(int i=0; i<length; i++)
        {
            pnt = pnt->rLink;
            tmp = pnt->data;
            personArray.push_back(tmp);
        }
        return true;
    }
//    将所有信息打印到屏幕上
    bool Output()
    {
        DoubleLinkNode<Type> *pnt = &head;
        for(int i=0; i<length; i++)
        {
            pnt = pnt->rLink;
            cout << pnt->data;
        }
        return true;
    }
//    根据No编号搜索个人信息
    DoubleLinkNode<Type>* SearchNo(PersonNo &thisNo)
    {
        DoubleLinkNode<Type> *pnt = head.rLink;
        while(pnt != NULL)
        {
            if(pnt->data.getNo() == thisNo)
                return pnt;
            pnt = pnt->rLink;
        }
        return NULL;
    }
//    插入一个新的元素
    bool PushBack(Type& data)
    {
        DoubleLinkNode<Type>* pnt = &head;
        for(int i=0; i<length; i++)
        {
            pnt = pnt->rLink;
        }
        DoubleLinkNode<Type>* tmp = new DoubleLinkNode<Type>();
        tmp->data = data;
        tmp->lLink = pnt;
        tmp->rLink = pnt->rLink;
        pnt->rLink = tmp;

        length ++;
        return true;
    }
};


#endif // DOUBLELINKEDLIST_H_INCLUDED
