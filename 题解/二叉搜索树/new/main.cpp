#include <iostream>
#include <cstring>

using namespace std;

struct node
{
    int val;
    node *left, *right;
};

int p;

// 插入：小值左结点，大于等于右孩子结点 返回插入后的根节点
node* insert(node *root, int val)
{
    if (!root)
    {
        root = new node();
        root->val = val;
    }
    else if (root->val < val)
    {
        root->right = insert(root->right, val);
    }
    else if (root->val > val)
    {
        root->left = insert(root->left, val);
    }
    return root;
}

void outans(node *root, int arr[])
{
    if(!root)return ;
    arr[p ++] = root->val;
    outans(root->left, arr);
    outans(root->right, arr);
    return ;
}
void deal(node *root, char inarr[], int outarr[],int outarr2[], int n)
{
    for(int i=0; i<n; i++)
    {
        root = insert(root, inarr[i]-'0');
    }
    p=0;
    outans(root, outarr);
    p=0;
    outans(root, outarr2);
}
int main()
{
    int n;

    bool f;
    cin >> n;
    while(n)
    {
        char str[11];
        int ans[11],ans2[11];
        int tmparr[11],tmparr2[11];

        cin >> str;
        int len = strlen(str);

        node *root = NULL;
        deal(root, str, ans, ans2, len);
        while(n --)
        {
            cin >> str;
            node *root = NULL;
            deal(root, str, tmparr, tmparr2, len);
            f = true;
            for(int i=0; i<len; i++)
            {
                if(ans[i] != tmparr[i])
                {
                    f = false;
                    break;
                }
                if(ans2[i] != tmparr2[i])
                {
                    f = false;
                    break;
                }
            }
            if(f)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        cin >> n;
    }
    return 0;
}
