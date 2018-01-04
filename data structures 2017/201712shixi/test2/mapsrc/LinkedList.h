#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED

#include <iostream>
using namespace std;

///////////用于保存双向链表的结点数据类型///////////////
template<typename Type>
struct DoubleLinkNode
{
  Type data;
  DoubleLinkNode<Type>* lLink;
  DoubleLinkNode<Type>* rLink;

  DoubleLinkNode(DoubleLinkNode<Type>* pre=NULL,DoubleLinkNode<Type>*suc=NULL)
  {
    lLink=pre;
    rLink=suc;
  }

  DoubleLinkNode(const Type& elem, DoubleLinkNode<Type>* pre=NULL,DoubleLinkNode<Type>* suc=NULL)
  {
    data=elem;
    lLink=pre;
    rLink=suc;
  }
  friend ostream& operator<<(ostream& os,DoubleLinkNode<Type>& node)
  {
    os << node.data;
    return os;
  }

};



///////////////////双向链表的实现//////////////////////////
template<typename Type>
class DoubleLinkedList
{
private:
  DoubleLinkNode<Type> head;
  int length;
public:
  DoubleLinkedList():length(0) {head.lLink=head.rLink=NULL;}
  DoubleLinkedList(vector<Type>& typeArray);
  void MakeEmpty();
  ~DoubleLinkedList();
  bool Output(vector<Type>& personArray);
  bool Output();
  DoubleLinkNode<Type>* SearchNo(int thisNo);
  bool PushBack(Type& data);
  bool DeleteOne(int thisNo);
};

template<typename Type>
DoubleLinkedList<Type>::DoubleLinkedList(vector<Type>& typeArray)
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

template<typename Type>
void DoubleLinkedList<Type>::MakeEmpty()
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

template<typename Type>
DoubleLinkedList<Type>::~DoubleLinkedList()
{
  MakeEmpty();
  head.lLink=head.rLink=NULL;
}

template<typename Type>
bool DoubleLinkedList<Type>::Output(vector<Type>& personArray)
{
  personArray.clear();
  DoubleLinkNode<Type> *pnt = &head;
  Type tmp;
  for(int i=0; i<length; i++)
    {
      pnt = pnt->rLink;
      tmp = pnt->data;
      personArray.push_back(tmp);
    }
  return true;
}

template<typename Type>
bool DoubleLinkedList<Type>::Output()
{
  DoubleLinkNode<Type> *pnt = &head;
  for(int i=0; i<length; i++)
    {
      pnt = pnt->rLink;
      cout << pnt->data;
    }
  return true;
}

template<typename Type>
DoubleLinkNode<Type>* DoubleLinkedList<Type>::SearchNo(int thisNo)
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

template<typename Type>
bool DoubleLinkedList<Type>::PushBack(Type& data)
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

template<typename Type>
bool DoubleLinkedList<Type>::DeleteOne(int thisNo)
{
  DoubleLinkNode<Type> *thisDelete = this->SearchNo(thisNo);
  if(thisDelete->rLink == NULL)
    {
      thisDelete->lLink->rLink = NULL;
      delete thisDelete;
      this->length --;
      return true;
    }
  DoubleLinkNode<Type> *tmpl = thisDelete->lLink;
  DoubleLinkNode<Type> *tmpr = thisDelete->rLink;
  tmpr->lLink = thisDelete->lLink;
  tmpl->rLink = thisDelete->rLink;
  delete thisDelete;
  this->length --;
  return true;
}

#endif // DOUBLELINKEDLIST_H_INCLUDED
