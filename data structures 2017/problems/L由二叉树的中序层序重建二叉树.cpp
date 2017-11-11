using namespace std;

#include <iostream>
#include <queue>
#include <cstdio>

#define MaxN 10000

struct Node//二叉树节点
{
    int data;
    Node *leftChild;
    Node *RgihtChild;
    Node()
    {
        leftChild = NULL;
        RgihtChild = NULL;
    }
};

struct TmpNode
{
    int left;
    int right;
    int index;
    Node** pnt;
};

int arr_cengci[MaxN];//层次遍历的结果
int arr_mid[MaxN];//中序遍历的结果

//递归重建二叉树 当前节点index在区间（left，right）中为根节点
Node* ReBuild(int index, int left, int right)
{
    Node *root;

    queue<TmpNode> myq;
    TmpNode tmp;
    tmp.index = index ++;
    tmp.left = left;
    tmp.right = right;
    tmp.pnt = &root;
    myq.push(tmp);

    while(myq.size())
    {
        TmpNode thisNode = myq.front();//get the front of myq

        int i;//get the position of index
        for(i=thisNode.left; i<=thisNode.right; i++)
        {
            if(arr_cengci[thisNode.index] == arr_mid[i])
                break;
        }
        *thisNode.pnt = (Node*)new Node();
        (*thisNode.pnt)->data = arr_cengci[thisNode.index];

        if(thisNode.left < i)
        {
            tmp.index = index ++;
            tmp.left = thisNode.left;
            tmp.right = i-1;
            tmp.pnt = &(*thisNode.pnt)->leftChild;
            myq.push(tmp);
        }

        if(i < thisNode.right)
        {
            tmp.index = index ++;
            tmp.left = i+1;
            tmp.right = thisNode.right;
            tmp.pnt = &(*thisNode.pnt)->RgihtChild;
            myq.push(tmp);
        }
        myq.pop();
    }
    return root;
}

void pre(Node *root)//递归 前序遍历
{
    if(root == NULL)return ;
    cout << root->data << " ";
    pre(root->leftChild);
    pre(root->RgihtChild);
}

void post(Node *root)//递归 后序遍历
{
    if(root == NULL)return ;
    post(root->leftChild);
    post(root->RgihtChild);
    cout << root->data << " ";
}

int main()
{
//    freopen("data.txt", "r", stdin);

    int n;
    cin >> n;//读取数据
    for(int i=1; i<=n; i++)
        cin >> arr_cengci[i];
    for(int i=1; i<=n; i++)
        cin >> arr_mid[i];

    int index = 1;
    Node *root = ReBuild(index, 1, n);//重建

    pre(root);//前序遍历
    cout << endl;
    post(root);//后序遍历

    return 0;
}
