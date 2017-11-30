using namespace std;

#include <iostream>
#define MaxN 1000000
#define ValMax 99999
int arr[MaxN];
int n;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void Up(int posi)
{
    if(posi == 0)
        return ;
    int father = (posi-1)/2;
    if(arr[father] > arr[posi])
    {
        swap(arr[father], arr[posi]);
        Up(father);
    }
}
void Down(int posi)
{
    int left = 2*posi + 1;
    int right = 2*posi + 2;
    if(arr[left] < arr[right])
    {
        if(arr[posi] > arr[left])
        {
            swap(arr[left], arr[posi]);
            Down(left);
        }
    }
    else
    {
        if(arr[right] < arr[posi])
        {
            swap(arr[right], arr[posi]);
            Down(right);
        }
    }
}
int main()
{
    int tmp;
    for(int i=0; i<MaxN; i++)
    {
        arr[i] = ValMax;
    }
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        arr[i] = tmp;
        Up(i);
    }
    while(arr[0] != ValMax)
    {
        cout << arr[0] << " ";
        arr[0] = ValMax;
        Down(0);
    }
    return 0;
}