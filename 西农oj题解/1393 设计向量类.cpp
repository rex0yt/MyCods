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
    //创建一个含num个元素的向量vec1，其中每个元素的值初始化为0
    Vector vec1(num);
    //输出vec1中的每个元素的值
    cout<<vec1<<endl;
    //从键盘端输入的元素存储到vec1中
    cin>>vec1;
    //用vec1初始化一个新的Vector 常量对象vec2
    cout<<vec1<<endl;

    const Vector vec2=vec1;
    cout<<vec2<<endl;

    Vector vec3(num);
    //用vec2给vec3赋值
    vec3=vec2;
    cout<<vec3<<endl;

    return 0;
}
