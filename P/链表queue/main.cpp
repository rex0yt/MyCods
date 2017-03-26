#include <iostream>

using namespace std;

struct Node{//创建链表结点
    int data;
    Node* next;
};
Node* rear = NULL, *front = NULL;//初始化队列头尾指针
int count = 0;//统计队列中元素的个数

void push(int data){//在队尾插入数据
    Node* p = new(Node);
    p->data = data;
    p->next = NULL;
    if(NULL != rear)rear->next = p;
    rear = p;
    if(NULL == front)front = p;
    count ++;
    return ;
}
int pop(){//在队头删除数据
    int data;
    Node* p = front;
    front = p->next;
    data = p->data;
    delete(p);
    count --;
    return data;
}
int getFront(){//获得队头数据
    int data = front->data;
    return data;
}
int isEmpty(){//判断队列是否为空
    if(NULL == front)return 1;
    return 0;
}
void printQueue(){//输出整个队列
    Node* p = front;
    while(NULL != p){
        cout << p->data << " ";
        p = p->next;
    }
}
int main(){

    return 0;
}
