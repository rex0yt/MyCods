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

int arr_pre[MaxN];//前序遍历的结果
int arr_mid[MaxN];//中序遍历的结果

//递归重建二叉树 当前节点index在区间（left，right）中为根节点
Node* ReBuild(int index, int left, int right)
{
    Node *root;
    int posi;

    for(posi=left; posi<=right; posi++)//寻找根的位置
    {
        if(arr_pre[index] == arr_mid[posi])
            break;
    }
    root = new Node;
    root->data = arr_mid[posi];//赋值

    if (posi > left)
    {
        root->leftChild = ReBuild(index+1, left, posi-1);
    }
    if (posi < right)
    {
        root->RgihtChild = ReBuild(index+posi-left+1, posi+1, right);
    }
    return root;
}

void post(Node *root)//递归 后序遍历
{
    if(root == NULL)return ;
    post(root->leftChild);
    post(root->RgihtChild);
    cout << root->data << " ";
}

void cengci(Node *root)//利用队列 层次遍历
{
    Node tmp;
    queue<Node> ique;
    ique.push(*root);
    while(!ique.empty())//当队列不为空 加入后继结点
    {
        tmp = ique.front();
        ique.pop();
        if(tmp.leftChild)
        {
            ique.push(*tmp.leftChild);
        }
        if(tmp.RgihtChild)
        {
            ique.push(*tmp.RgihtChild);
        }
        cout << tmp.data << " ";
    }
    cout << endl;
}

int main()
{
//    freopen("data.txt", "r", stdin);

    int n;
    cin >> n;//读取数据
    for(int i=1; i<=n; i++)
        cin >> arr_pre[i];
    for(int i=1; i<=n; i++)
        cin >> arr_mid[i];

    Node *root = ReBuild(1, 1, n);//重建

    cengci(root);

    post(root);

    return 0;
}
