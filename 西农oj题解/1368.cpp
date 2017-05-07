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
                cout << "无病人就诊" << endl;
            }else{
                cout << "病历号为" << Queue.front() << "的病人就诊" << endl;
                Queue.pop();
            }
            break;
        default:
            cout << "输入命令不合法！" << endl;
        }
        cin >> order;
    }
    cout << "今天不再接收病人排队，下列排队的病人依次就诊：";
    while(!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }

    return 0;

}
