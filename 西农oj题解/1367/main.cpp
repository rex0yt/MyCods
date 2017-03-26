#include <iostream>

using namespace std;

struct Node//´´½¨Á´±í½áµã
{
    char data;
    Node* next;
};
Node* top = NULL;//Õ»¶¥Ö¸Õë

void push(char data) //Ñ¹Õ»
{
    Node* p = (Node*)new(Node);
    p->data = data;
    p->next = top;
    top = p;
    return ;
}
char pop() //µ¯Õ»
{
    char data;
    Node* p = top;
    top = p->next;
    data = p->data;
    delete(p);
    return data;
}
bool isEmpty() //ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
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
        if(isEmpty()) cout << "Æ¥Åä" << endl;
        else cout << "²»Æ¥Åä" << endl;
    }

    return 0;
}
