#include <bits/stdc++.h>

using namespace std;
const int defaultSize=1000;

template<typename Type> class SeqList
{
public:
    Type * data;
    int maxSize;
    int last;
    void Resize(int newSize);
public:
    SeqList(int sz=defaultSize);
    SeqList(const SeqList<Type>& lst);
    ~SeqList();

    bool Insert(int loc, const Type& val);
    bool Remove(int loc, Type& val);
    int  Search(const Type& val) const;
    int LowBound(const Type& val)const;
    bool Turn();

    bool Locate(int loc)const;
    bool Empty() const;
    bool Full()const;

    int Length()const;
    int Size() const;
    bool Hebing(const SeqList<Type>& left);
    friend ostream& operator<<(ostream& os, const SeqList<Type>& left)
    {
        for(int i=0; i<left.last; i++)
        {
            os<<left.data[i]<<" ";
        }
        os << left.data[left.last] << endl;
//        os<<endl;
        return os;
    }
};
template<typename Type>int SeqList<Type>::LowBound(const Type& val)const
{
    if(val <= data[0])return 1;
    else if(val >= data[last])return last+1;
    for(int i=0; i<=last; i++)
    {
        if(val>=data[i] && val <=data[i+1])
            return i+2;
    }
    return 0;
}
template<typename Type> bool SeqList<Type>::Hebing(const SeqList<Type>& left)
{
    if(this->Empty() || left.Empty())
        return false;
    if(this->Length()+left.Length() > this->Size())
    {
        this->Resize(this->Length()+left.Length());
    }
    int pnt;
    for(int i=0; i<=left.last; i++)
    {
        pnt = this->LowBound(left.data[i]);
        this->Insert(pnt, left.data[i]);
    }
    return true;
}
template<typename Type> bool SeqList<Type>::Turn()
{
    if(Empty())
    {
        return false;
    }
    for(int i=0; i<=last/2; i++)
    {
        swap(data[i], data[last-i]);
    }
    return true;
}
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

template<typename Type> bool SeqList<Type>::Full() const
{
    return last==maxSize-1;
}
template<typename Type> bool SeqList<Type>::Empty() const
{
    return last==-1;
}
template<typename Type> int SeqList<Type>::Length() const
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
    int tmp;
    int index;
    int n;
    SeqList<int> mylist;

    cin >> n;//输入顺序表
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        mylist.Insert(i+1, tmp);
    }
//    cout << mylist;

    cin >> tmp >> index;//插入一个数字
    mylist.Insert(index, tmp);
    cout << mylist;

    cin >> index;//删除一个数字
    if(mylist.Locate(index))
        mylist.Remove(index,tmp);
    cout << mylist;

    cin >> tmp;//查找一个数字
    index = mylist.Search(tmp);
    if(index == 0)
        cout << "Not found" << endl;
    else
        cout << index<< endl;

    mylist.Turn();//转置
    cout << mylist;

    SeqList<int> newlist;//创建新表
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        newlist.Insert(i+1, tmp);
    }
    mylist.Hebing(newlist);//合并操作
    cout << mylist;
    cout << endl;

    return 0;
}


