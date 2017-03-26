#include <iostream>

using namespace std;

int num, rem;//层数 剩余
int N;
char ch;

/*
int countN(int x){//计算N层的沙漏需要的个数
    int sum = 1;
    if(x == 1)return sum;
    for(int i = 3; i <= x; i += 2){
        sum += i * 2;
    }
    return sum;
}
*/

void calcN(int &num, int &rem) //计算层数和剩余数量
{
    if(N == 1)
    {
        num = 1;
        rem = 0;
        return ;
    }
    int sum = 1;
    for(num = 3;; num += 2)
    {
        sum += num *2;
        rem = N - sum;
        if(sum == N)return ;
        else if(sum > N)
        {
            rem += num * 2;
            num -= 2;
            return ;
        }
    }
}
void printN(int n)
{
    int numBlank = (num - n)/2;
    for(int i = 0; i < numBlank; i ++)
    {
        cout << " ";
    }
    for(int i = 0; i < n; i ++)
    {
        cout << ch;
    }
    cout << endl;
    return ;
}
void printGraphics(int n)
{
    if(n == 1)
    {
        printN(1);
        return ;
    }
    printN(n);
    printGraphics(n - 2);
    printN(n);
    return ;
}

int main()
{
    cin >> N >> ch;
    calcN(num, rem);
    //cout << num << endl << rem;
    printGraphics(num);
    cout << rem << endl;

    return 0;
}
