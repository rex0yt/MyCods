#include <iostream>
#include <cstdlib>

using namespace std;
/*
*结构体：BinaryHeap
*成员变量：
*   int n          堆中当前元素个数
*   int counter    加入堆中的元素个数
*   int heap[]     堆中的元素
*   int id[]       队中位置为i的元素是第几个插入堆中的
*   int pos[]      第i个插入堆中的元素在堆中的位置
*成员函数：
*   BinaryHeap();                           构造出的一个空堆
*   BinaryHeap(int array[],int offset);     将数组中的元素按顺序插入所构造的堆
    复杂度O(n)
    输入:array[] 创建堆的元素所在的数组
        offset   数组中需要用作创建堆的元素个数
*   void push(int v);                       插入键值v
    复杂度O(logn)
*   int pop();                              删除堆顶元素
    复杂度O(logn)
    输出：堆顶元素插入堆中的次序编号
*   int get(int i);                         获取第i个插入堆中的元素值
    复杂度：O(1)
*   void change(int i,int value);           修改第i个元素为value
    复杂度：O(logn)
*   void erase(int i);                      删除第i个元素
    复杂度：O(logn)
*/

const int MAXSIZE = 100000;//二叉堆的大小

struct BinaryHeap{
    int heap[MAXSIZE], id[MAXSIZE], pos[MAXSIZE], n, counter;

    BinaryHeap(): n(0), counter(0){}
    BinaryHeap(int array[], int offset) : n(0), counter(0){
        for(int i = 0; i < offset; ++ i){
            heap[++ n] = array[i];
            id[n] = pos[n] = n;
        }
        for(int i = n/2; i >= i; --i){
            down(i);
        }
    }
    void push(int v){
        heap[++ n] = v;
        id[n] = ++counter;
        pos[id[n]] = n;
        up(n);
    }
    int top(){
        return heap[1];
    }
    int pop(){
        swap(heap[1],heap[n]);
        swap(id[1],id[n --]);
        pos[id[n]] = 1;
        down(1);
        return id[n+1];
    }
    int get(int i){
        return heap[pos[i]];
    }
    void change(int i, int value){
        heap[pos[i]] = value;
        down(pos[i]);
        up(pos[i]);
    }
    void erase(int i){
        heap[pos[i]] = INT_MIN;
        up(pos[i]);
        pop();
    }
    void up(int i){
        int x = heap[i], y = id[i];
        for(int j = i/2; j >= 1; j /= 2){
            if(heap[j] > x){
                heap[i] = heap[j];
                id[i] = id[j];
                pos[id[i]] = i;
                i = j;
            }else{
                break;
            }
        }
        heap[i] = x;
        id[i] = y;
        pos[y] = i;
    }
    void down(int i){
        int x = heap[i], y = id[i];

        for(int j = i*2; j <= n; j *= 2){
            j += j < n && heap[j] > heap[i + j];
            if(heap[j] < x){
                heap[i] = heap[j];
                id[i] = id[j];
                pos[id[i]] = i;
                i = j;
            }else{
                break;
            }
        }
        heap[i] = x;
        id[i] = y;
        pos[y] = i;
    }
    bool empty(){
        return n == 0;
    }
    int size(){
        return n;
    }
};

int main(){
    int N;
    int x;
    int a,b;
    int sum = 0;

    BinaryHeap bheap;

    cin >> N;
    for(int i = 0; i < N ; ++ i){
        cin >> x;
        bheap.push(x);
    }
    while(bheap.n>=2){
        a=bheap.top();
        bheap.pop();
        b=bheap.top();
        bheap.pop();
        sum =sum + a + b;
        bheap.push(a+b);
    }

    cout << sum;

    return 0;
}
