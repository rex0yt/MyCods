#include <iostream>

using namespace std;

const int N = 1000+10;

struct Node
{
    int data;
    Node* Left;
    Node* Right;
};

Node* root;
int a[N], b[N];
int n;

int findp(int p)
{
    for(int i = 0; i < n; i ++)
    {
        if(b[i] == p)return i;
    }
    return -1;
}

Node* createTree(int &pnt, int front, int back)
{
    int pFather = findp(a[pnt ++]);
    Node *root = (Node*)new(Node);
    root->data = b[pFather];
    root->Left = NULL;
    root->Right = NULL;

    if(front <= pFather - 1)
    {
        root->Left = createTree(pnt, front, pFather-1);
    }
    if(pFather + 1 <= back)
    {
        root->Right = createTree(pnt, pFather+1, back);
    }

    return root;
}
void deleteTree(Node *root)
{
    if(root->Left != NULL)deleteTree(root->Left);
    if(root->Right != NULL)deleteTree(root->Right);
    delete(root);
}
void printTree(Node *proot)
{
    if(proot == NULL)return ;
    printTree(proot->Left);
    printTree(proot->Right);
    cout << proot->data;
    if(proot != root)cout << " ";//格式要求 行末不能有多余空格
    return ;
}

int main()
{
    while(cin >> n)
    {
        for(int i = 0; i < n; i ++)cin >> a[i];
        for(int i = 0; i < n; i ++)cin >> b[i];
        int pnt = 0;
        root = createTree(pnt, 0, n-1);
        printTree(root);
        cout << endl;
        deleteTree(root);
    }

    return 0;
}
