#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> a;
    vector <int> b;
    int len_a = 0, len_b = 0;
    int tmp, tmp_i;
    int i, j;
    bool f = false;

    // �����һ������
    cin >> len_a;
    for(int i = 0; i < len_a; i ++){
        cin >> tmp;
        a.push_back(tmp);
    }
    //�����µ�����Ԫ��
    cin >> tmp >> tmp_i;
    a.insert(a.begin() + tmp_i - 1, tmp);
    for(int i = 0; i < a.size() - 1; i ++)
        cout << a[i] << " ";
        cout << a.back() << endl;

    //ɾ��Ԫ��
    cin >> tmp_i;
    a.erase(a.begin() + tmp_i - 1);
    for(int i = 0; i < a.size() - 1; i ++)
        cout << a[i] << " ";
        cout << a.back() << endl;

    //����һ��Ԫ��
    cin >> tmp;
    for(int i = 0; i < a.size(); i ++){
        if(tmp == a[i]){
            cout << i+1 << endl;
            f = true;
            break;
        }
    }
    if(!f)cout << "Not found" << endl;

    //����Ԫ�ز����
    for(int i = a.size()-1; i > 0; i --)
        cout << a[i] << " ";
        cout << a[0] << endl;

    //��ȡ�ڶ������Ա�
    cin >> len_b;
    for(int i = 0; i < len_b; i++){
        cin >> tmp;
        b.push_back(tmp);
    }

    //�ϲ����Ա����
    vector <int> c;

    for(i = a.size() - 1, j = 0; i >= 0, j <= b.size() - 1;){
        if(a[i] < b[j]){
            c.push_back(a[i --]);
        }else{
            c.push_back(b[j ++]);
        }
    }
    if(i >= 0){
        for(; i >= 0; i --)
            c.push_back(a[i]);
    }else{
        for(; j < b.size(); j ++)
            c.push_back(b[j]);
    }
    for(int i = 0; i < c.size() - 1; i ++)
        cout << c[i] << " ";
        cout << c.back() << endl;

    return 0;
}
