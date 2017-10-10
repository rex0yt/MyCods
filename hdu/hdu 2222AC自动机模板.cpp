#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;

const int charSize = 26;    //maximum size of char set
const char charFront = 'a'; //first char

struct node //node of Trie
{
    node *next[charSize];
    node *fail;
    int sum;//count of (endChar equal thisChar)
};

node *root;
node* q[600000];

void InitTrie(node *&root)
{
    root = new node;
    for(int i=0; i<charSize; i++)
        root->next[i] = NULL;
    root->fail = 0;
    root->sum = 0;
}

void Insert(char *s)
{
    node *p = root;
    node *newnode;

    for(int i=0; s[i]; i++)
    {
        int x = s[i] - charFront;
        if(p->next[x] == NULL)
        {
            newnode = new node;
            for(int j=0; j<charSize; j++)//initial the new node
                newnode->next[j] = NULL;
            newnode->sum = 0;
            newnode->fail = NULL;
            p->next[x] = newnode;
        }
        p = p->next[x];
    }
    p->sum ++;
}

void BuildFailPoiner(node *root)
{


    int head = 0;
    int tail = 1;
    q[head] = root;
    node *p;
    node *temp;

    while(head < tail)
    {
        temp = q[head ++];
        for(int i=0; i<charSize; i++)
        {
            if(temp->next[i] != NULL)
            {
                if(temp == root)
                {
                    temp->next[i]->fail = root;
                }
                else
                {
                    p = temp->fail;
                    while(p)
                    {
                        if(p->next[i] != NULL)
                        {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL)
                        temp->next[i]->fail = root;
                }
                q[tail ++] = temp->next[i];
            }
        }
    }
}

bool travel(node* root)
{
    for(int i=0; i<charSize; i++)
    {
        if(root->next[i] != NULL)
        {
            cout <<root->next[i] <<" " <<char(charFront+i) <<" " <<root->next[i]->fail <<" " <<root->next[i]->sum <<endl;
            travel(root->next[i]);
        }
    }
    return true;
}

int AcAutomain(char *ch)
{
    int cnt = 0;

    node *p = root;
    int len = strlen(ch);

    for(int i=0; i<len; i++)
    {
        int x = ch[i] - charFront;
        while(p->next[x]==NULL && p!=root)
        {
            p = p->fail;
        }
        p = p->next[x];
        if(p == NULL)p = root;
        node *temp = p;
        while(temp != root)
        {
            if(temp->sum >= 0)
            {
                cnt += temp->sum;
                temp->sum = -1;
            }
            else
                break;
            temp = temp->fail;
        }
    }
    return cnt;
}

char tmp[100];
char s[100000+100];

int main()
{
//    freopen("data.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int testcase;
    cin >> testcase;
    while(testcase --)
    {
        InitTrie(root);
        int n;
        cin >>n;
        for(int i=0; i<n; i++)
        {
            cin >>tmp;
            Insert(tmp);
        }
        BuildFailPoiner(root);
        cin >> s;
        int ans = AcAutomain(s);
        cout <<ans <<"\n";
    }
    return 0;
}
