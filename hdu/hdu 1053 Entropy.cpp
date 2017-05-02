#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

const int NN = 100000;

typedef struct node
{
    int weight;
    node* left;
    node* right;
    /*优先队列的优先级*/
    bool operator < (const node &a) const
    {
        return weight > a.weight;
    }
} Node;

char str[NN];
int wei[500];

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
    int counti;
    cin >> str;

    while(strcmp(str,"END"))
    {
        priority_queue <Node> pq;
        Node tmp;
        counti = 0;
        for(int i = 0; i < 500; i ++)
        {
            wei[i] = 0;
        }

        int pre = strlen(str) * 8;
        cout << pre << " " ;

        for(int i = 0; i < (int)strlen(str); i ++)
        {
            wei[str[i] - 'A'] ++;
        }
        for(int i = 0; i < 500; i ++)
        {
            if(wei[i])
            {
                counti ++;
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
            ans = (int)strlen(str);

        }
        cout << ans << " ";
        printf("%.1f\n",(float)pre/ans);

        memset(str, 0, sizeof(char));
        cin >> str;
    }
}
int main()
{
    calc();
    return 0;
}
