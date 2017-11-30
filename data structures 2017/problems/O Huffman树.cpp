using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>

#define MaxN 300

struct Node
{
    int data;
    int wei;
    Node *left, *right;
    Node()
    {
        data = 0;
        wei = 0;
        left = right = NULL;
    }
    friend bool operator<(Node a, Node b)
    {
        return a.wei < b.wei;
    }
};

struct compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->wei > b->wei;
    }
};

int n;
Node arr[MaxN];
int Solution[MaxN];

void Huff(Node *root, int len, int thisData)
{
    if(root == NULL)
        return ;
    if(root->data == thisData)
    {
        cout << (char)root->data << " " << root->wei << " ";
        for(int i=0; i<len; i++)
            cout << Solution[i];
        cout << endl;
        return ;
    }

    Solution[len] = 1;
    Huff(root->right, len+1, thisData);
    Solution[len] = 0;
    Huff(root->left, len+1, thisData);
}

int main()
{
    char tmp;
    int arrTmp[MaxN];
    for(int i=0; i<MaxN; i++)
    {
        arr[i].wei = 0;
        arr[i].data = 0;
        arrTmp[i] = 0;
    }

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        arrTmp[tmp] ++;
    }

    priority_queue <Node*, vector<Node*>, compare> myPq;

    Node *pntNode = NULL;
    int len = 0;
    for(int i=0; i<MaxN; i++)
    {
        if(arrTmp[i] != 0)
        {
            pntNode = new Node;
            pntNode->wei = arrTmp[i];
            pntNode->data = i;
            myPq.push(pntNode);
            arr[len].data = i;
            arr[len].wei = arrTmp[i];
            len ++;
        }
    }

    Node *pnt1=NULL, *pnt2=NULL;
    while(myPq.size() > 1)
    {
        pnt1 = myPq.top();
        myPq.pop();
        pnt2 = myPq.top();
        myPq.pop();
        pntNode = new Node;
        pntNode->wei = pnt1->wei + pnt2->wei;
        pntNode->left = pnt1;
        pntNode->right = pnt2;

        myPq.push(pntNode);
    }

    pntNode = myPq.top();

    sort(arr,arr+len);
    for(int i=len-1; i>=0; i--)
    {
        Huff(pntNode, 0, arr[i].data);
    }

    return 0;
}