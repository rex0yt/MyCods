/** \brief 坑 字符串由单个字符组成
 *
 */

#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int NN = 100000;

typedef struct node
{
    int weight;
    //char data;
    node* left;
    node* right;
    /*优先队列的优先级*/
    bool operator < (const node &a) const
    {
        return weight > a.weight;
    }
} Node;

string str;
int wei[26];

void abc(Node *a,int i, int &ans)
{
    if(a->left==NULL && a->right == NULL)
    {
        ans += a->weight * i;
        return ;
    }
    abc(a->left, i + 1, ans);
    abc(a->right, i + 1, ans);
}

void calc()
{
    int m;
    int val;
    cin >> m;
    int counti = 0;

    while(m --)
    {
        priority_queue <Node> pq;
        Node tmp;
        counti = 0;
        for(int i = 0; i < 26; i ++)
        {
            wei[i] = 0;
        }
        cin >> val;
        str.clear();
        cin >> str;

        for(int i = 0; i < (int)str.length(); i ++)
        {
            wei[str[i] - 'a'] ++;
        }
        for(int i = 0; i < 26; i ++)
        {
            if(wei[i])
            {
                counti ++;
                //tmp.data = 'a' + i;
                tmp.weight = wei[i];
                tmp.left = NULL;
                tmp.right = NULL;
                pq.push(tmp);
            }
        }

        /*建立haffuman树*/
        Node *root, *a, *b;
        while(1)
        {
            a = (Node *)new(Node);
            *a = pq.top();
            pq.pop();
            if(pq.empty())
            {
                break;
            }
            b = (Node *)new(Node);
            *b = pq.top();
            pq.pop();

            root = (Node *)new(Node);
            root->weight = a->weight + b->weight;
            root->left = a;
            root->right = b;

            pq.push(*root);
        }

        /*求出最小编码值*/
        int ans = 0;
        abc(a, 0, ans);
        if(counti == 1)
        {
            ans = (int)str.length();

        }
        if(ans <= val)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}
int main()
{
    calc();
    return 0;
}
