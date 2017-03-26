// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cstring>

using namespace std;

char s[30];
char m[] = { 'q','b','s','w','q','b','s','y','q','b','s','w','q','b','s','\0' };
char sol[50];

int len, len_p;
bool h=false,f = true;//h 是否输出零，f 是否存在小数

void to_b(char tmp) {//大小写转换 
	switch (tmp) {
	case '1':cout << "壹"; break;
	case '2':cout << "贰"; break;
	case '3':cout << "叁"; break;
	case '4':cout << "肆"; break;
	case '5':cout << "伍"; break;
	case '6':cout << "陆"; break;
	case '7':cout << "柒"; break;
	case '8':cout << "捌"; break;
	case '9':cout << "玖"; break;
	case 's':cout << "拾"; break;
	case 'b':cout << "佰"; break;
	case 'q':cout << "仟"; break;
	case 'w':cout << "万"; break;
	case 'y':cout << "亿"; break;
	}
	return ;
}

int main() {
	//init
	cin >> s; len = strlen(s);
	//将整数和小数分开 
	int p_dot = 0;while ((s[p_dot] != '.') && (p_dot < 25))p_dot++;
	//判断位数
	if ((p_dot >= 0) && (p_dot <= 17))len_p = p_dot;else { len_p = len; f = false; }
	//判断位数是否溢出 
	if (len_p >= 17) { cout << "输入数据应小于一亿亿"; return 0; }
	//输出前驱 
	cout << "人民币";
	//处理整数 
	for (int i = 1; i <= 2 * len_p; i++)
		if (i % 2 == 1)sol[i] = s[(i - 1) / 2];
			else sol[i] = m[15 - len_p + i / 2];
	for(int i=1; i <= 2 * len_p;){
		if (sol[i] != '0') {
			if (h) {cout << "零";h = false;}
			to_b(sol[i]);
			to_b(sol[i + 1]);
		}
		else {
			if (sol[i + 1] == 'y' || sol[i + 1] == 'w')to_b(sol[i + 1]);
			h = true;
		}
		i += 2;
	}
	if(!(len==1&&s[0]=='0'))cout << "元";
	//处理小数部分
	if (f) {
		if (s[p_dot + 1] != '0') {to_b(s[p_dot + 1]); cout << "角";}
			else cout << "零";
		if (s[p_dot + 2] != '0') {to_b(s[p_dot + 2]);cout << "分" << endl;}
	}
	else cout << "整\n";
	return 0;
}
