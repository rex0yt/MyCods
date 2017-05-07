#include <iostream>

using namespace std;

struct Node//����������
{
    char data;
    Node* next;
};
Node* top = NULL;//ջ��ָ��

void push(char data) //ѹջ
{
    Node* p = (Node*)new(Node);
    p->data = data;
    p->next = top;
    top = p;
    return ;
}
char pop() //��ջ
{
    char data;
    Node* p = top;
    top = p->next;
    data = p->data;
    delete(p);
    return data;
}
bool isEmpty() //�ж�ջ�Ƿ�Ϊ��
{
    if(NULL == top)return true;
    return false;
}

bool charmatch(char &a, char &b)
{
    if('(' == a && ')' == b)return true;
    else if('[' == a && ']' == b)return true;
    else if('{' == a && '}' == b)return true;
    return false;
}
int main()
{
    char ch;
    while(cin >> ch)
    {
        while(ch != '#')
        {
            if(isEmpty())
            {
                push(ch);
            }
            else
            {
                if(charmatch((*top).data, ch))
                {
                    pop();
                }
                else
                {
                    push(ch);
                }
            }
            cin >> ch;
        }
        if(isEmpty()) cout << "ƥ��" << endl;
        else cout << "��ƥ��" << endl;
    }

    return 0;
}
