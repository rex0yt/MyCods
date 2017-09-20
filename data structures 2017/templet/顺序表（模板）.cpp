#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
const int defaultSize=1000;

template<typename Type> class SeqList
{
private:
    Type * data;
    int maxSize;
    int last;
    void Resize(int newSize);
public:
    SeqList(int sz=defaultSize);
    SeqList(const SeqList<Type>& lst);
    SeqList<Type>& operator=(const SeqList<Type>& rlst);
    ~SeqList();

    bool Insert(int loc, const Type& val);
    bool Remove(int loc, Type& val);
    int  Search(const Type& val) const;
    bool Update(int loc, const Type& val);
    bool GetData(int loc, Type& val) const;

    bool Locate(int loc)const;
    bool Empty() const;
    bool Full()const;

    int length()const;
    int Size() const;
    friend ostream& operator<<(ostream& os, const SeqList<Type>& left)
    {
        for(int i=0; i<=left.last; i++)
        {
            os<<left.data[i]<<" ";
        }
        os<<endl;
        return os;
    }
};
template<typename Type> SeqList<Type>::SeqList(int sz)
{
    maxSize=sz;
    data=new Type [maxSize];
    last=-1;
}
template<typename Type> SeqList<Type>::~SeqList()
{
    delete [] data;
}
template<typename Type> SeqList<Type>::SeqList(const SeqList<Type>& lst)
{
    maxSize=lst.maxSize;
    data=new Type [maxSize];
    last=lst.last;
    for(int i=0; i<=last; i++)
    {
        data[i]=lst.data[i];
    }
}
template<typename Type> SeqList<Type>& SeqList<Type>::operator=(const SeqList<Type>& rlst)
{
    if(this==&rlst)
        return *this;
    if(rlst.maxSize<=maxSize)
    {
        for(int i=0; i<=rlst.last; i++)
        {
            data[i]=rlst.data[i];
        }
        last=rlst.last;
    }
    else
    {
        delete [] data;
        maxSize=rlst.maxSize;
        data= new Type [maxSize];
        last=rlst.last;
        for(int i=0; i<=last; i++)
        {
            data[i]=rlst.data[i];
        }
    }
    return *this;
}
template<typename Type> bool SeqList<Type>::Full() const
{
    return last==maxSize-1;
}
template<typename Type> bool SeqList<Type>::Empty() const
{
    return last==-1;
}
template<typename Type> int SeqList<Type>::length() const
{
    return last+1;
}
template<typename Type> int SeqList<Type>::Size() const
{
    return maxSize;
}
template<typename Type> bool SeqList<Type>::Locate(int loc) const
{
    if(loc>=1&&loc<=last+1)
        return true;
    else
        return false;
}
template<typename Type> bool SeqList<Type>::Insert(int loc, const Type& val)
{
    if(Full())
    {
        Resize(2*maxSize);
    }
    if(loc<1||loc>last+2)
    {
        return false;
    }
    for(int i=last; i>=loc-1; i--)
    {
        data[i+1]=data[i];
    }
    data[loc-1]=val;
    last++;
    return true;
}
template<typename Type> bool SeqList<Type>::Remove(int loc, Type& val)
{
    if(Empty())
    {
        cout<<"The list is Empty"<<endl;
        return false;
    }
    if(!Locate(loc))
    {
        return false;
    }
	val = data[loc-1];
    for(int i=loc-1; i<last; i++)
    {
        data[i]=data[i+1];
    }
    last--;
    return true;
}
template<typename Type> int SeqList<Type>::Search(const Type& val) const
{
    for(int i=0; i<=last; i++)
    {
        if(data[i]==val)
            return i+1;
    }
    return 0;
}
template<typename Type> bool SeqList<Type>::Update(int loc, const Type& val)
{
    if(Locate(loc))
    {
        data[loc-1]=val;
        return true;
    }
    else
    {
        return false;
    }
}
template<typename Type> bool SeqList<Type>::GetData(int loc, Type& val) const
{
    if(Locate(loc))
    {
        val=data[loc-1];
        return true;
    }
    else
    {
        return false;
    }
}
template<typename Type> void SeqList<Type>::Resize(int newSize)
{
    if(newSize<1)
    {
        exit(1);
    }
    Type* newData= new Type[newSize];
    if(!newData)
    {
        exit(1);
    }
    for(int i=0; i<=last; i++)
    {
        newData[i]=data[i];
    }
    delete [] data;
    data=newData;
    maxSize=newSize;
}


int main()
{
    SeqList<int> lst;
    for(int i=1; i<=200; i++)
    {
        lst.Insert(i,i);
    }
    cout << lst << endl;
    int val;
    for(int i=lst.length(); i>=1; i--)
    {
        lst.Remove(i,val);
        cout<<lst;
    }

    SeqList<double> lstd;
    for(int i=1; i<=200; i++)
    {
        lstd.Insert(i,(rand()%200+(rand()%100)/100.0));
    }
    cout<<lstd<<endl;

    return 0;
}


