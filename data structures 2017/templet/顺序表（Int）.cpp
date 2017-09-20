#include <iostream>
#include <cstdlib>

using namespace std;
const int defaultSize=1000;

typedef int Type;

class SeqList
{
private:
    Type *data;//�±�λ��[1,last]
    int maxSize;
    int last;
    void Resize(int newSize);
public:
    SeqList(int sz=defaultSize);//���캯�� ����Ĭ�ϴ�С��˳���
    SeqList(const SeqList& lst);//�������캯�� ���
    SeqList& operator=(const SeqList& rlst);//��ֵ����
    ~SeqList();//�������� �ͷ�����Ŀռ�

    bool Insert(int loc, const Type& val);//���뺯�� ��locλ�ò���Type��������
    bool Remove(int loc, Type& val);//ɾ������ ɾ������λ�õĽڵ� ����ԭ�ڵ�
    int  Search(const Type& val) const;//�������� �����������ĵ�һ��index
    bool Update(int loc, const Type& val);//���º���
    bool GetData(int loc, Type& val) const;

    bool Locate(int loc)const;
    bool Empty() const;
    bool Full()const;

    int length()const;
    int Size() const;
    friend ostream& operator<<(ostream& os, const SeqList &left);
};
SeqList::SeqList(int sz)
{
    maxSize=sz;
    data=new Type [maxSize];
    last=-1;
}
SeqList::~SeqList()
{
    delete [] data;
}
SeqList::SeqList(const SeqList& lst)
{
    maxSize=lst.maxSize;
    data=new Type [maxSize];
    last=lst.last;
    for(int i=0; i<=last; i++)
    {
        data[i]=lst.data[i];
    }
}
SeqList& SeqList::operator=(const SeqList& rlst)
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
bool SeqList::Full() const
{
    return last==maxSize-1;
}
bool SeqList::Empty() const
{
    return last==-1;
}
int SeqList::length() const
{
    return last+1;
}
int SeqList::Size() const
{
    return maxSize;
}
bool SeqList::Locate(int loc) const
{
    if(loc>=1&&loc<=last+1)
        return true;
    else
        return false;
}
bool SeqList::Insert(int loc, const Type& val)
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
bool SeqList::Remove(int loc, Type& val)
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
int SeqList::Search(const Type& val) const
{
    for(int i=0; i<=last; i++)
    {
        if(data[i]==val)
            return i+1;
    }
    return 0;
}
bool SeqList::Update(int loc, const Type& val)
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
bool SeqList::GetData(int loc, Type& val) const
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
void SeqList::Resize(int newSize)
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
ostream& operator<<(ostream& os, const SeqList& left)
{
    for(int i=0; i<=left.last; i++)
    {
        os<<left.data[i]<<" ";
    }
    os<<endl;
    return os;
}

int main()
{
    SeqList lst;
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

    return 0;
}


