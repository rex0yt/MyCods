// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <cstring>

using namespace std;

char s[30];
char m[] = { 'q','b','s','w','q','b','s','y','q','b','s','w','q','b','s','\0' };
char sol[50];

int len, len_p;
bool h=false,f = true;//h �Ƿ�����㣬f �Ƿ����С��

void to_b(char tmp) {//��Сдת�� 
	switch (tmp) {
	case '1':cout << "Ҽ"; break;
	case '2':cout << "��"; break;
	case '3':cout << "��"; break;
	case '4':cout << "��"; break;
	case '5':cout << "��"; break;
	case '6':cout << "½"; break;
	case '7':cout << "��"; break;
	case '8':cout << "��"; break;
	case '9':cout << "��"; break;
	case 's':cout << "ʰ"; break;
	case 'b':cout << "��"; break;
	case 'q':cout << "Ǫ"; break;
	case 'w':cout << "��"; break;
	case 'y':cout << "��"; break;
	}
	return ;
}

int main() {
	//init
	cin >> s; len = strlen(s);
	//��������С���ֿ� 
	int p_dot = 0;while ((s[p_dot] != '.') && (p_dot < 25))p_dot++;
	//�ж�λ��
	if ((p_dot >= 0) && (p_dot <= 17))len_p = p_dot;else { len_p = len; f = false; }
	//�ж�λ���Ƿ���� 
	if (len_p >= 17) { cout << "��������ӦС��һ����"; return 0; }
	//���ǰ�� 
	cout << "�����";
	//�������� 
	for (int i = 1; i <= 2 * len_p; i++)
		if (i % 2 == 1)sol[i] = s[(i - 1) / 2];
			else sol[i] = m[15 - len_p + i / 2];
	for(int i=1; i <= 2 * len_p;){
		if (sol[i] != '0') {
			if (h) {cout << "��";h = false;}
			to_b(sol[i]);
			to_b(sol[i + 1]);
		}
		else {
			if (sol[i + 1] == 'y' || sol[i + 1] == 'w')to_b(sol[i + 1]);
			h = true;
		}
		i += 2;
	}
	if(!(len==1&&s[0]=='0'))cout << "Ԫ";
	//����С������
	if (f) {
		if (s[p_dot + 1] != '0') {to_b(s[p_dot + 1]); cout << "��";}
			else cout << "��";
		if (s[p_dot + 2] != '0') {to_b(s[p_dot + 2]);cout << "��" << endl;}
	}
	else cout << "��\n";
	return 0;
}
