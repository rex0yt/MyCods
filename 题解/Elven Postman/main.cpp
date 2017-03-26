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
int a[N];
int m, n;

int findBiggerThanP(int p)//p�Ǹ��ڵ���±� ͨ����С������ֳ�����
{
    int i;
    for(i = p + 1; i < n; i ++)
    {
        if(a[i] > a[p])return i;//��һ����a[p]���Ԫ�ص��±�
    }
    return i;
}

Node* createTree(int front, int back)//������ ������E С���ұ�W
{
    Node *root = (Node*)new(Node);
    root->data = a[front];
    root->Left = NULL;
    root->Right = NULL;

    int p = findBiggerThanP(front);

    if(front + 1 <= p - 1)
    {
        root->Right = createTree(front + 1, p - 1);
    }
    if(p <= back)
    {
        root->Left = createTree(p, back);
    }

    return root;
}

void findTreeNode(Node *root, int x)
{
    if(root->data == x)
    {
        cout << endl;
    }
    else if(root->data < x)
    {
        cout << "W";
        findTreeNode(root->Left, x);
    }
    else
    {
        cout << "E";
        findTreeNode(root->Right, x);
    }
    return ;
}
void deleteTree(Node *root)
{
    if(root->Left != NULL)deleteTree(root->Left);
    if(root->Right != NULL)deleteTree(root->Right);
    delete(root);
}

int main()
{
    int times = 0;
    int x;
    cin >> times;
    while(times --)
    {
        cin >> n;
        for(int i = 0; i < n; i ++)
        {
            cin >> a[i];
        }
        root = createTree(0, n - 1);
        cin >> m;
        for(int i = 0; i < m; i ++)
        {
            cin >> x;
            findTreeNode(root, x);
        }
        deleteTree(root);
    }

    return 0;
}
