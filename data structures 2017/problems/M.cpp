using namespace std;

#include <iostream>
#include <queue>
#include <cstdio>
#include <cmath>

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

int getDeepth(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->leftChild == NULL && root->RgihtChild==NULL)
    {
        return 1;
    }
    return max(getDeepth(root->leftChild),getDeepth(root->RgihtChild))+1;
}

bool isBalanced(Node* root)
{
    if(root == NULL)
        return true;

    int left = getDeepth(root->leftChild);
    int right = getDeepth(root->RgihtChild);

    if(abs(left-right) > 1)
        return false;
    if(!isBalanced(root->leftChild))
        return false;
    if(!isBalanced(root->RgihtChild))
        return false;
    return true;
}

int main()
{
//    freopen("data.txt", "r", stdin);

    int n;
    cin >> n;//读取数据
    for(int i=1; i<=n; i++)
        cin >> arr_mid[i];
    for(int i=1; i<=n; i++)
        cin >> arr_cengci[i];

    int index = 1;
    Node *root = ReBuild(index, 1, n);//重建

    if(isBalanced(root))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << endl;
    return 0;
}
