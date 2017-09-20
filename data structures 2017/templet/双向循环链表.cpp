#include <iostream>

using namespace std;

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
};
template<typename Type>
class CircleDoubleLinkedList
{
private:
      DoubleLinkNode<Type>* first;
public:
      CircleDoubleLinkedList()
      {
            first=new DoubleLinkNode<Type>();
            first->lLink=first;
            first->rLink=first;
      }
      void MakeEmpty()
      {
            DoubleLinkNode<Type>* del;
            while(first->rLink!=first)
            {
                  del=first->rLink;
                  first->rLink=del->rLink;
                  delete del;
            }
            first->lLink=first;
      }
      ~CircleDoubleLinkedList()
      {
            MakeEmpty();
            delete first;
      }
      void InputRear(const Type& elem)
      {
            DoubleLinkNode<Type>* newNode=new DoubleLinkNode<Type>(elem);
            DoubleLinkNode<Type>* pre=first;
            DoubleLinkNode<Type>* suc;
            while(pre->rLink!=first)
            {
                  pre=pre->rLink;
            }
            suc=pre->rLink;
            newNode->rLink=suc;
            newNode->lLink=pre;
            suc->lLink=newNode;
            pre->rLink=newNode;
      }
       void CopyList(const CircleDoubleLinkedList<Type>& lst)
      {
            DoubleLinkNode<Type> iter=first->rLink;
            while(iter!=first)
            {
                  InputRear(iter->data);
                  iter=iter->rLink;
            }
      }
      CircleDoubleLinkedList(const CircleDoubleLinkedList<Type>& lst)
      {
            CircleDoubleLinkedList();
            CopyList(lst);
      }
      CircleDoubleLinkedList<Type>& operator=(const CircleDoubleLinkedList<Type>& lst)
      {
            if(this==&lst)
                  return *this;
            MakeEmpty();
            CopyList(lst);
            return *this;
      }
      DoubleLinkNode<Type>* Locate(int loc, int sign)
      {
            DoubleLinkNode<Type>* iter=first;
            int cnt=-1;
            do
            {
                  cnt++;
                  if(cnt==loc)
                        return iter;
                  iter=(sign==0)?iter->rLink:iter->lLink;
            }while(iter!=first);
            return NULL;
      }
      bool Insert(int loc, const Type& elem,int sign)
      {
            if(loc<1)
                  return false;
            DoubleLinkNode<Type>* pre=Locate(loc-1,sign);
            if(pre==NULL)
                  return false;
            DoubleLinkNode<Type>* suc=(sign==0)?pre->rLink:pre->lLink;
            DoubleLinkNode<Type>* newNode=new DoubleLinkNode<Type>(elem);
            if(sign==0)
            {
                  newNode->rLink=suc;
                  newNode->lLink=pre;
                  pre->rLink=newNode;
                  suc->lLink=newNode;
            }
            else
            {
                  newNode->rLink=pre;
                  newNode->lLink=suc;
                  pre->lLink=newNode;
                  suc->rLink=newNode;
            }
            return true;
      }
      bool Remove(int loc, Type& elem, int sign)
      {
            if(loc<1)
                  return false;
            DoubleLinkNode<Type>* pre=Locate(loc-1,sign);
            if(pre==NULL)
                  return false;
            DoubleLinkNode<Type>* del=(sign==0)?pre->rLink:pre->lLink;
            DoubleLinkNode<Type>* suc=(sign==0)?del->rLink:del->lLink;
            elem=del->data;
            if(sign==0)
            {
                  pre->rLink=suc;
                  suc->lLink=pre;
            }
            else
            {
                  pre->lLink=suc;
                  suc->rLink=pre;
            }
            delete del;
            return true;
      }
      DoubleLinkNode<Type>* Search(const Type& elem, int sign) const
      {
            DoubleLinkNode<Type>* iter=(sign==0)?first->rLink:first->lLink;
            while(iter!=first)
            {
                  if(iter->data==elem)
                        return iter;
                  iter=(sign==0)?iter->rLink:iter->lLink;
            }
            return NULL;
      }
      bool GetData(int loc, Type& elem, int sign) const
      {
            if(loc<1)
                  return false;
            DoubleLinkNode<Type>* nd=Locate(loc,sign);
            if(nd==NULL)
                  return false;
            elem=nd->data;
            return true;
      }
      bool SetData(int loc, const Type& elem, int sign)
      {
            if(loc<1)
                  return false;
            DoubleLinkNode<Type>* nd=Locate(loc,sign);
            if(nd==NULL)
                  return false;
            nd->data=elem;
            return true;
      }
      void OutPut(int sign=0)
      {
            DoubleLinkNode<Type>* iter= (sign==0)?first->rLink:first->lLink;
            while(iter!=first)
            {
                  cout<<iter->data<<" ";
                  iter= (sign==0)?iter->rLink:iter->lLink;
            }
            cout<<endl;
      }
};
int main()
{
    CircleDoubleLinkedList<int> lst;
    for(int i=1;i<=10;i++)
    {
          lst.Insert(i,i,1);
    }
    lst.OutPut(0);
    lst.OutPut(1);
    if(lst.Search(5,0))
    {
          cout<<"yes"<<endl;
    }
    else
    {
          cout<<"no"<<endl;
    }
    lst.SetData(10,100,0);
    int val;
    for(int i=10;i>0;i--)
    {
          lst.Remove(i,val,1);
          lst.OutPut(0);
    }
    return 0;
}
