#include <iostream>

using namespace std;

class Vector
{
    int *data;
    int len;

public:
    Vector(int _num=0):len(_num)
    {
        data = new int(len);
        for(int i=0; i<len; i++)
        {
            data[i] = 0;
        }
    }
    friend ostream& operator<<(ostream &os,const Vector&left)
    {
        for(int i=0; i<left.len; i++)
        {
            cout << left.data[i] << " ";
        }
        return os;
    }
    friend istream& operator>>(istream &is, Vector &left)
    {
        for(int i=0; i<left.len; i++)
        {
            cin >> left.data[i];
        }
        return is;
    }
    Vector& operator=(const Vector& left)
    {
        len = left.len;
        delete []data;
        data = new int(len);
        for(int i=0; i<len; i++)
        {
            data[i] = left.data[i];
        }
        return *this;
    }
};


int main()
{

    int num;
    cin>>num;
    //����һ����num��Ԫ�ص�����vec1������ÿ��Ԫ�ص�ֵ��ʼ��Ϊ0
    Vector vec1(num);
    //���vec1�е�ÿ��Ԫ�ص�ֵ
    cout<<vec1<<endl;
    //�Ӽ��̶������Ԫ�ش洢��vec1��
    cin>>vec1;
    //��vec1��ʼ��һ���µ�Vector ��������vec2
    cout<<vec1<<endl;

    const Vector vec2=vec1;
    cout<<vec2<<endl;

    Vector vec3(num);
    //��vec2��vec3��ֵ
    vec3=vec2;
    cout<<vec3<<endl;

    return 0;
}
