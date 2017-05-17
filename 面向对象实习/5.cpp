#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
};

class Vect
{
    node *head;
    int len;
public:
    Vect();
    Vect(int *a, int n);
    Vect(int n);
    ~Vect();
    Vect(const Vect &right);
    int GetArrX(int x) const;
    void SetArrX(int x, int val);
    int GetLen() const;
    void PrintAll() const;

};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int len;
    int x, val;
    Vect v1(a, 5);
    cin >> len;
    Vect v2(len);
    v1.PrintAll();
    v2.PrintAll();
    cin >> x >> val;
    v1.SetArrX(x, val);
    Vect v3(v1);
    v1.PrintAll();
    v3.PrintAll();
    return 0;
}

Vect::Vect():len(0)
{
    head = NULL;
}
Vect::Vect(int *a, int n):len(n)
{
    head = new node;
    head->val = a[0];
    node *p = head;
    for(int i=1; i<n; i++)
    {
        p->next = new node;
        p = p->next;
        p->val = a[i];
    }
    p->next = NULL;
}

Vect::Vect(int n):len(n)
{
    if(n==0)
    {
        head=NULL;
    }
    else
    {
        head = new node;
        head->val = 0;
        node *p = head;
        for(int i=0; i<n-1; i++)
        {
            p->next = new node;
            p = p->next;
            p->val = 0;
        }
        p->next = NULL;
    }
}
int Vect::GetArrX(int x) const
{
    if(x<=0 ||x >len)
    {
        cout << "out of boundary" << endl;
    }
    else
    {
        node *p = head;
        x --;
        while(x--)
        {
            p=p->next;
        }
        return p->val;
    }
    return 0;
}
int Vect::GetLen() const
{
    return len;
}
void Vect::PrintAll() const
{
    node *p = head;
    int n = len-1;
    while(n--)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << p->val << endl;
    return ;
}
Vect::~Vect()
{
    node *p = head;
    while(head)
    {
        p = p->next;
        delete head;
        head = p;
    }
    return ;
}
void Vect::SetArrX(int x, int val)
{
    if(x<=0 ||x >len)
    {
        cout << "out of boundary" << endl;
    }
    else
    {
        node *p = head;
        x --;
        while(x--)
        {
            p=p->next;
        }
        p->val = val;
    }
    return ;
}
Vect::Vect(const Vect &right)
{
    len = right.len;
    if(len == 0)
    {
        head = NULL;
    }
    else
    {
        head = new node;
        head->val = right.GetArrX(1);
        int n = len-1;
        node *p =head, *pnt = right.head;
        while(n --)
        {
            p->next = new node;
            p = p->next;
            pnt = pnt->next;
            p->val = pnt-> val;
        }
        p->next = NULL;
    }
}
