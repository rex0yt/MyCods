/*哈夫曼树 直接二叉堆解决（优先队列）*/
#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int NN = 20000 + 100;

struct cmp
{
    bool operator ()(int &a,int &b)
    {
        return a>b;//最小值优先
    }
};

priority_queue <int, vector<int>, cmp> pq;
int n;
long long sum = 0;

int main()
{
    int x;
    int a, b;
    cin >> n;
    while(n --)
    {
        cin >> x;
        pq.push(x);
    }
    while(1)
    {
        a = pq.top();
        pq.pop();
        if(pq.empty())break;
        b = pq.top();
        pq.pop();
        sum += a+b;
        pq.push(a+b);
    }
    cout << sum << endl;
    return 0;
}
