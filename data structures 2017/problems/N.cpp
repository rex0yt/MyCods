using namespace std;

#include <iostream>
#include <queue>
struct Node
{
    char ch;
    int wei;
//    friend bool operator<(Node right, Node left)
//    {
//        return right.wei>left.wei;
//    }
};
int main()
{
    string str;
    cin >> str;

//    priority_queue<Node> myq;
    vector<Node> myVec;
    Node tmp;
    int maxWei = 0;
    int wei = 0;
    for(int i=0; i<(int)str.length(); i++)
    {
        switch (str[i])
        {
            case '(':
                wei ++;
                maxWei = max(maxWei, wei);
                break;
            case ')':
                wei --;
                break;
            case ',':
                break;
            default:
                tmp.ch = str[i];
                tmp.wei = wei;
                myVec.push_back(tmp);
        }
    }

    for(int i=1; i<=maxWei; i++)
    {
        for(int j=0; j<myVec.size(); j++)
        {
            if(myVec[j].wei == i)
            {
                cout << myVec[j].ch;
//                myVec.erase(myVec+j);
            }
        }
    }
    cout << endl;

    return 0;
}