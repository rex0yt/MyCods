#include <iostream>
#include <cstdio>
using namespace std;
 
const int MaxN = 100000;
 
//template<typename Type>
//class Node
//{
//
//};
 
template<typename Type>
class BinaryTree
{
private:
    Type *tree;
    int cnt;
    int maxsize;
public:
    BinaryTree(int _cnt=0, int _maxsize = MaxN)
    :cnt(_cnt),maxsize(_maxsize)
    {
        tree = new Type[maxsize];
        for(int i=0; i<maxsize; i++)
        {
            tree[i] = 0;
        }
    }
    friend istream& operator>>(istream& is, BinaryTree &btree)
    {
        cin >>btree.cnt;
        for(int i=0; i<btree.cnt; i++)
        {
            cin >>btree.tree[i];
        }
        return is;
    }
    bool pre(int root=0)
    {
        if(tree[root]==0)
        {
            return false;
        }
        cout <<tree[root] <<" ";
        pre(2*root + 1);
        pre(2*root + 2);
        if(root == 0)
        {
            cout <<endl;
        }
        return true;
    }
    bool mid(int root=0)
    {
        if(tree[root]==0)
        {
            return false;
        }
        mid(2*root + 1);
        cout <<tree[root] <<" ";
        mid(2*root + 2);
        if(root == 0)
        {
            cout <<endl;
        }
        return true;
    }
    bool suf(int root=0)
    {
        if(tree[root]==0)
        {
            return false;
        }
        suf(2*root + 1);
        suf(2*root + 2);
        cout <<tree[root] <<" ";
        if(root == 0)
        {
            cout <<endl;
        }
        return true;
    }
};
int main()
{
 
    BinaryTree<int> btree;
    cin >>btree;
 
    btree.pre();
    btree.mid();
    btree.suf();
 
    return 0;
}
