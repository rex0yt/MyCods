#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue <int> Queue;
    char order;
    int No;

    cin >> order;
    while(order != 's' && order != 'S'){
        switch(order){
        case 'a':case 'A':
            cin >> No;
            Queue.push(No);
            break;

        case 'n':case 'N':
            if(Queue.empty()){
                cout << "�޲��˾���" << endl;
            }else{
                cout << "������Ϊ" << Queue.front() << "�Ĳ��˾���" << endl;
                Queue.pop();
            }
            break;
        default:
            cout << "��������Ϸ���" << endl;
        }
        cin >> order;
    }
    cout << "���첻�ٽ��ղ����Ŷӣ������ŶӵĲ������ξ��";
    while(!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }

    return 0;

}
