#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

//Node *aHeadPnt, *bHeadPnt;
Node *aHead, *bHead, *cHead;

void Listcreate(Node* &head){
    Node* p, *rear;
    int n, data;
    head = (Node*)new(Node);
    rear = head;
    cin >> n;
    for(int i = 0; i < n; i ++){
        p = (Node*)new(Node);
        cin >> data;
        (*p).data = data;
        (*rear).next = p;
        rear = p;
    }
    (*rear).next = NULL;
}

void Listinsert(Node* &head){
    int data, loc;
    cin >> data >> loc;
    Node *pnt = head, *p;
    while(-- loc){
        pnt = pnt->next;
    }
    //pnt = pnt->next;
    p = (Node*)new(Node);
    p->data = data;
    (*p).next = pnt->next;
    pnt->next = p;
}
void Listprint(Node* &head){
    Node* p = head->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Listdelete(Node* &head){
    int loc;
    cin >> loc;
    Node *pnt = head ,*p;
    while(-- loc){
        pnt = pnt->next;
    }
    p = (*pnt).next;
    pnt->next = p->next;
    delete(p);
}
void Listfind(Node *head){
    int data, loc = 0;
    bool isfind = false;

    cin >> data;
    Node* pnt = (*head).next;
    while(pnt != NULL){
        if((*pnt).data == data){
            isfind = true;
            break;
        }
        pnt = pnt->next;
        loc ++;
    }
    loc ++;
    if(isfind)cout << loc;
    else cout << "Not found";
    cout << endl;
}
void Listtrans(Node* &phead, Node* &newhead){
    newhead = (Node*)new(Node);
    newhead->next = NULL;

    Node* pnt = (*phead).next;
    Node* p;

    while(pnt != NULL){
        p = (Node*)new(Node);
        p->data = pnt->data;
        pnt = pnt->next;
        p->next = (*newhead).next;
        (*newhead).next = p;
    }
}
void Listmerge(){
    Node *pntb = (*bHead).next, *pntc = (*cHead).next;
    while(pntb != NULL && pntc != NULL){
        if((*pntb).data < (*pntc).data){
            cout << (*pntb).data << " ";
            pntb = pntb->next;
        }else{
            cout << (*pntc).data << " ";
            pntc = pntc->next;
        }
    }
    Node* p;
    if(pntb != NULL)p = pntb;
    else p = pntc;
    while(p != NULL){
        cout << (*p).data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    Listcreate(aHead);
    Listinsert(aHead);
    Listprint(aHead);
    Listdelete(aHead);
    Listprint(aHead);
    Listfind(aHead);
    Listtrans(aHead, cHead);
    Listprint(cHead);
    Listcreate(bHead);
    Listmerge();

    return 0;
}
