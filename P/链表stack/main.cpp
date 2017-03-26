#include <iostream>

using namespace std;

struct Node//创建链表结点
{
    int data;
    Node* next;
};
Node* top = NULL;//栈顶指针

void push(int data){//压栈
    Node* p = new(Node);
    p->data = data;
    p->next = top;
    top = p;
    return ;
}
int pop(){//弹栈
    int data;
    Node* p = top;
    top = p->next;
    data = p->data;
    delete(p);
    return data;
}
int isEmpty(){//判断栈是否为空
    if(NULL == top)return 1;
    return 0;
}

int main(){

    return 0;
}
