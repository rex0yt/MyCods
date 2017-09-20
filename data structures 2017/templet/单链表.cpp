#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
template<typename Type>
struct LinkNode
{
    Type data;
    LinkNode* next;
    LinkNode(const Type& item, LinkNode<Type>* ptr=NULL)
    {
        data=item;
        next=ptr;
    }
 /*   LinkNode(LinkNode<Type>* ptr=NULL)
    {
        next=ptr;
    }*/
};
template<typename Type>
class SingleLinkedList
{
private:
    LinkNode<Type> * first;
public:
    SingleLinkedList()
    {
        first=NULL;
    }
    SingleLinkedList(const SingleLinkedList<Type>& L);
    SingleLinkedList<Type>& operator=(const SingleLinkedList<Type>& L);
    ~SingleLinkedList() {}

    void InputFront(const Type& elem);
    void InputRear(const Type& elem);

    void MakeEmpty();
    void CopyList(const SingleLinkedList<Type>& L);

    bool Insert(int i, const Type& x);
    bool Remove(int i, Type& x);
    LinkNode<Type>* Search(const Type& x) const ;

    LinkNode<Type>* Locate(int i) const ;
    bool GetData(int i, Type& x)const;
    bool SetData(int i, const Type& x);


    int Length() const;
    bool IsEmpty() const
    {
        return first==NULL;
    }
    bool IsFull() const
    {
        return false;
    }

    void Sort();
    friend ostream& operator<<(ostream& out, const SingleLinkedList<Type>& L)
    {
        LinkNode<Type> * iterator1=L.first;
        while(iterator1)
        {
            out<<iterator1->data<<" ";
            iterator1=iterator1->next;
        }
        out<<endl;
        return out;
    }
    friend istream& operator>>(istream& in, SingleLinkedList<Type>& L)
    {
        return in;
    }
};
template<typename Type>
void SingleLinkedList<Type>::InputFront(const Type& elem)
{
    LinkNode<Type>* newNode = new LinkNode<Type> (elem);
    newNode->next=first;
    first=newNode;
}
template<typename Type>
void SingleLinkedList<Type>::InputRear(const Type& elem)
{
    LinkNode<Type>* rear=NULL;
    LinkNode<Type>* newNode=new LinkNode<Type> (elem);
    if(NULL==first)
    {
        first=newNode;
    }
    else
    {
        rear=first;
        while(rear->next)
        {
            rear=rear->next;
        }
        rear->next=newNode;
    }
}
template<typename Type>
bool SingleLinkedList<Type>::Insert(int i, const Type& x)
{
    if(i<1)
    {
        cerr<<""<<endl;
        return false;
    }
    LinkNode<Type> * newNode = new LinkNode<Type>(x);
    if(i==1)
    {
        newNode->next=first;
        first=newNode;
        return true;
    }
    LinkNode<Type> * pre=first;
    for(int j=1;j<i-1;j++)
    {
        if(pre==NULL)
            break;
        pre=pre->next;
    }
    if(pre==NULL)
        return false;
    newNode->next=pre->next;
    pre->next=newNode;
    return true;
}
template<typename Type>
bool SingleLinkedList<Type>::Remove(int i, Type& x)
{
    if(i<1)
    {
        cerr<<""<<endl;
        return false;
    }
    LinkNode<Type>* del;
    LinkNode<Type>* pre;
    if(i==1)
    {
        del=first;
        x=del->data;
        first=first->next;
        delete del;
        return true;
    }
    pre=first;
    for(int j=1;j<i-1;j++)
    {
       if(pre==NULL)
       {
           cerr<<""<<endl;
           return false;
       }
       pre=pre->next;
    }
    del=pre->next;
    pre->next=del->next;
    x=del->data;
    delete del;
    return true;
}
template<typename Type>
LinkNode<Type>* SingleLinkedList<Type>::Search(const Type& x) const
{
    LinkNode<Type>* iter=first;
    while(iter)
    {
        if(iter->data==x)
            return iter;
        iter=iter->next;
    }
    return iter;
}
template<typename Type>
LinkNode<Type>* SingleLinkedList<Type>::Locate(int i) const
{
    LinkNode<Type>* iter=first;
    if(i<1)
        return NULL;
    int num=0;
    while(iter)
    {
        num++;
        if(num==i)
            return iter;
        iter=iter->next;
    }
    return NULL;
}
template<typename Type>
bool SingleLinkedList<Type>::GetData(int i, Type& x)const
{
    LinkNode<Type>* nd=Locate(i);
    if(nd)
    {
        x=nd->data;
        return true;
    }
    return false;

}
template<typename Type>
bool SingleLinkedList<Type>::SetData(int i, const Type& x)
{
    LinkNode<Type>* nd=Locate(i);
    if(nd)
    {
        nd->data=x;
        return true;
    }
    return false;
}
template<typename Type>
int SingleLinkedList<Type>::Length() const
{

}
template <typename Type>
void SingleLinkedList<Type>::Sort()
{
      //外层循环迭代指针
      LinkNode<Type>* iter1=first;
      LinkNode<Type>* preIter1=first;
      //内层循环迭代指针
      LinkNode<Type>* iter2;
      LinkNode<Type>* preIter2;
      //标记最小值所在结点
      LinkNode<Type>* mark;
      LinkNode<Type>* preMark;

      LinkNode<Type>* tmp;

      while(iter1&&iter1->next)
      {
            mark=iter1;
            preMark=preIter1;

            iter2=iter1;
            preIter2=preIter1;

            while(iter2)
            {
                  if(iter2->data<mark->data)
                  {
                        mark=iter2;
                        preMark=preIter2;
                  }
                  preIter2=iter2;
                  iter2=iter2->next;
            }
            if(iter1==first)//将最小值所在结点放到表头
            {
                  tmp=mark->next;
                  mark->next=first;
                  first=mark;
                  preMark->next=tmp;
                  iter1=first;
            }
            else if(iter1!=mark)
            {
                  tmp=mark->next;
                  mark->next=preIter1->next;
                  preIter1->next=mark;
                  preMark->next=tmp;
                  iter1=mark;
            }
            preIter1=iter1;
            iter1=iter1->next;
            //cout<<*this<<endl;
      }
}
int main()
{
    SingleLinkedList<int> lst;
    int elem;
    LinkNode<int>* nd;
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        lst.Insert(i+1,rand()%100);
    }
    cout <<lst << endl;
    lst.Sort();
    cout<<lst<<endl;
    //lst.Remove(3,elem);
    //cout<<lst;
    //nd=lst.Search(3);
    //cout<<nd->data;
    return 0;
}
